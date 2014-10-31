#include "RandomRegionExtractor.h"

#include "AutoThresholdExtractor.h"
#include <random>
#include <chrono>
#include <ctime>
#include <training_lib/Sample.h>
#include <rec_system/image_processing/filters/thresholding/Thresholder.h>
#include <rec_system/plate_detection/region_detection/cser/CSERDetector.h>
#include <rec_system/plate_detection/region_detection/cser/filters/ERFilterEmpty.h>
#include <rec_system/plate_detection/region_detection/cser/ExtremalRegion.h>
#include <iostream>

using namespace nprs;

RandomRegionExtractor::RandomRegionExtractor(
        sp<const Image> const& image,
        int numSamples,
        const Size &minSize,
        const Size &maxSize)
: _image(image),
  _numSamples(numSamples),
  _minSize(minSize),
  _maxSize(maxSize),
  _rng(std::chrono::system_clock::now().time_since_epoch().count()),
  _widthDist(minSize.width(), maxSize.width()),
  _heightDist(minSize.height(), maxSize.height())
{
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
