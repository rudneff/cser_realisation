#include "RandomRegionExtractor.h"

#include "AutoThresholdExtractor.h"
#include <random>
#include <chrono>
#include <ctime>
#include <training_lib/Sample.h>
#include <rec_system/image_processing/filters/thresholding/Thresholder.h>
#include <rec_system/image_processing/region_detection/cser/CSERDetector.h>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterEmpty.h>
#include <rec_system/image_processing/region_detection/cser/ExtremalRegion.h>
#include <iostream>

using namespace nprs;

RandomRegionExtractor::RandomRegionExtractor(
        sp<const Image> image,
        int numSamples,
        const Size &minSize,
        const Size &maxSize)
: _image(image),
  _numSamples(numSamples),
  _minSize(minSize),
  _maxSize(maxSize),
  _rng(std::time(0)),
  _widthDist(minSize.width(), maxSize.width()),
  _heightDist(minSize.height(), maxSize.height())
{
}

std::vector<Sample> RandomRegionExtractor::extractNMLightSamples() {
    CSERDetector detector(std::vector<sp<ERFilter>> {});
    std::vector<Sample> result;

    for (int i = 0; i < _numSamples; i++) {
        Rectangle bounds = chooseRandomRegion();
        auto regionImage = std::make_shared<Image>(_image->cropped(bounds));
        AutoThresholdExtractor extractor(regionImage);
        std::vector<Sample> extractedSamples = extractor.extractNMLightSamples();
        for (auto sample : extractedSamples) {
            result.push_back(sample);
        }
    }

    return result;
}

Rectangle RandomRegionExtractor::chooseRandomRegion() {
    int width = _widthDist(_rng);
    int height = _heightDist(_rng);
    std::uniform_int_distribution<int> xDist(0, _image->width()- width);
    std::uniform_int_distribution<int> yDist(0, _image->height() - height);

    return Rectangle(xDist(_rng), yDist(_rng), width, height);
}

bool RandomRegionExtractor::checkConstraints(const ExtremalRegion &reg) {
    return reg.bounds().width() >= _minSize.width() &&
           reg.bounds().height() >= _minSize.height() &&
           reg.bounds().width() <= _maxSize.width() &&
           reg.bounds().height() <= _maxSize.height();
}
