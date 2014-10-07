#include "NegativeImageInputSample.h"
#include <training_lib/input_sample_extractors/RandomRegionExtractor.h>

using namespace nprs;

NegativeImageInputSample::NegativeImageInputSample(
    sp<const Image> image, 
    int numSamples,
    const Size &minRegionSize,
    const Size &maxRegionSize)
: ImageInputSample(image), 
  _numSamples(numSamples), 
  _image(image),
  _minSize(minRegionSize),
  _maxSize(maxRegionSize)
{
}

up<SampleExtractor> NegativeImageInputSample::createExtractor() const {
    return up<RandomRegionExtractor>(new RandomRegionExtractor(_image, _numSamples, _minSize, _maxSize));
}
