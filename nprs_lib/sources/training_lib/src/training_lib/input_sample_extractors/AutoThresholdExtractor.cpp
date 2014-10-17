#include "AutoThresholdExtractor.h"
#include <common/image/Image.h>
#include <rec_system/image_processing/region_detection/cser/ExtremalRegion.h>
#include <rec_system/image_processing/filters/thresholding/OtsuThresholder.h>
#include <rec_system/image_processing/filters/thresholding/Thresholder.h>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterEmpty.h>
#include <rec_system/image_processing/region_detection/cser/CSERDetector.h>
#include <training_lib/Sample.h>
#include <rec_system/image_processing/feature_extraction/HogFeatureExtractor.h>

namespace nprs {

AutoThresholdExtractor::AutoThresholdExtractor(sp<const Image> image)
    : _image(image)
{
}

AutoThresholdExtractor::~AutoThresholdExtractor() {
}

std::vector<Sample> nprs::AutoThresholdExtractor::extractNMLightSamples() {
    std::vector<Sample> result;

    std::vector<sp<ERFilter>> filters;
    CSERDetector detector(filters);
    std::vector<ExtremalRegion> regions = detector.detect(*_image);
    std::sort(
        regions.begin(),
        regions.end(),
        [](const ExtremalRegion &a, const ExtremalRegion &b) {
            return a.threshold() < b.threshold();
        });

    OtsuThresholder otsu;
    int otsuThres = otsu.findThreshold(*_image) * 255;
    auto first = std::find_if(regions.begin(), regions.end(),
        [&](const ExtremalRegion &a) {
            return (a.threshold() > otsuThres - 5 && a.threshold() < otsuThres + 5);
        }
    );

    if (first != regions.end()) {
        auto maxSquare = first;
        for (auto it = first; it != regions.end() && it != first + 5; ++it) {
            if (it->bounds().area() > maxSquare->bounds().area()) {
                maxSquare = it;
            }
        }

        Thresholder thresholder;
        Image regImage = thresholder.threshold(_image->cropped(maxSquare->bounds().x(), maxSquare->bounds().y(), maxSquare->bounds().width(), maxSquare->bounds().height()));

        result.push_back(Sample(maxSquare->lightFeatures(), SampleType::NMLight, std::make_shared<Image>(regImage)));
    }

    return result;
}

std::vector<Sample> AutoThresholdExtractor::extractNMHeavySamples() {
    HogFeatureExtractor extractor;
    std::vector<float> fv = extractor.extract(*_image, 0, Rectangle(0, 0, _image->width(), _image->height()));
    return {Sample(fv, SampleType::NMHeavy)};
}

}
