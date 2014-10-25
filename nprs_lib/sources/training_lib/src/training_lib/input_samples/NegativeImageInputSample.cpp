#include "NegativeImageInputSample.h"
#include <training_lib/input_sample_extractors/LightRandomRegionExtractor.h>
#include <training_lib/input_sample_extractors/HeavyRandomRegionExtractor.h>

namespace nprs {

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

up<SampleExtractor> NegativeImageInputSample::createLightSampleExtractor() const {
    return up<LightRandomRegionExtractor>(new LightRandomRegionExtractor(_image, _numSamples, _minSize, _maxSize));
}

up<SampleExtractor> NegativeImageInputSample::createHeavySampleExtractor() const {
    return up<HeavyRandomRegionExtractor>(new HeavyRandomRegionExtractor(_image, _numSamples, _minSize, _maxSize));
}

}
