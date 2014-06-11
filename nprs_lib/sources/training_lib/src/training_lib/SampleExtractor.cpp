#include "SampleExtractor.h"

#include <algorithm>
#include <common/image/Image.h>
#include <rec_system/image_processing/region_detection/cser/ExtremalRegion.h>
#include <rec_system/image_processing/region_detection/cser/algorithm/CserAlgorithm.h>
#include <rec_system/image_processing/region_detection/CserDetector.h>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterEmpty.h>
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/image_processing/filters/thresholding/Thresholder.h>
#include <rec_system/image_processing/region_detection/cser/CSERDetector.h>
#include <common/image/Bitmap.h>
#include <common/image/ImageConverter.h>
#include <training_lib/Sample.h>

using namespace nprs;

std::vector<Sample> SampleExtractor::extractPositiveSample(const Bitmap &image, int numImages) {
    return extractPositiveSample(ImageConverter::convertRaw(image), numImages);
}

std::vector<Sample> SampleExtractor::extractPositiveSample(const Image &image, int numImages) {
    std::vector<Sample> result;

    CSERDetector detector( { pERFilter(new ERFilterEmpty()) } );
    std::vector<ExtremalRegion> regions = detector.detect(image);
    std::sort(regions.begin(), regions.end(), [] (const ExtremalRegion &a, const ExtremalRegion &b) { return a.threshold() < b.threshold(); });

    OtsuThresholder otsu;
    int otsuThres = otsu.findThreshold(image) * 255;
    auto first = std::find_if(regions.begin(), regions.end(), 
        [&] (const ExtremalRegion &a) {
            return (a.threshold() > otsuThres - 5 && a.threshold() < otsuThres + 5);
        }
    );

    if (first != regions.end()) {
        auto maxSquare = first;
        for (auto it = first; it != regions.end() && it != first + 5; it++) {
            if (it->bounds().area() > maxSquare->bounds().area()) {
                maxSquare = it;
            }
        }

        Thresholder thresholder;
        Image regImage = thresholder.threshold(image.cropped(maxSquare->bounds().x(), maxSquare->bounds().y(), maxSquare->bounds().width(), maxSquare->bounds().height()));

        result.push_back(Sample(*maxSquare, regImage));
    }

    return result;
}

