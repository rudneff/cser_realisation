#include "RandomRegionExtractor.h"

#include "AutoThresholdExtractor.h"
#include <random>
#include <training_lib/Sample.h>
#include <rec_system/image_processing/filters/thresholding/Thresholder.h>
#include <rec_system/image_processing/region_detection/cser/CSERDetector.h>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterEmpty.h>
#include <rec_system/image_processing/region_detection/cser/ExtremalRegion.h>

using namespace nprs;

RandomRegionExtractor::RandomRegionExtractor(sp<const Image> image, 
                                             int numSamples,
                                             const Size &minSize,
                                             const Size &maxSize)
    : _image(image),
      _numSamples(numSamples),
      _minSize(minSize),
      _maxSize(maxSize)
{
}

std::vector<Sample> RandomRegionExtractor::extractNMLightSamples() {
    CSERDetector detector(std::vector<sp<ERFilter>> { make_shared<ERFilterEmpty>() }); 
    std::vector<ExtremalRegion> regions = detector.detect(*_image);
    std::vector<Sample> result;
    for (int i = 0, step = regions.size() / _numSamples; i < regions.size(); i += step) {
        ExtremalRegion const& reg = regions[i];
        Thresholder thresholder;

        sp<Image> regImage = make_shared<Image>(
            thresholder.threshold(
                _image->cropped(
                    reg.bounds().x(),
                    reg.bounds().y(),
                    reg.bounds().width(),
                    reg.bounds().height())));

        result.push_back(
            Sample(
                reg.lightFeatures(),
                SampleType::NMLight,
                regImage));
    }

    return result;
}

bool RandomRegionExtractor::checkConstraints(const ExtremalRegion &reg) {
    return reg.bounds().width() >= _minSize.width() &&
           reg.bounds().height() >= _minSize.height() &&
           reg.bounds().width() <= _maxSize.width() &&
           reg.bounds().height() <= _maxSize.height();
}
