#include "NegativeImageInputSample.h"
#include <training_lib/input_sample_extractors/RandomRegionExtractor.h>

using namespace nprs;

NegativeImageInputSample::NegativeImageInputSample(sp<const Image> image, int numSamples)
: ImageInputSample(image), _numSamples(numSamples), _image(image)
{
}

sp<SampleExtractor> NegativeImageInputSample::createExtractor() const {
    return make_shared<RandomRegionExtractor>(_image, _numSamples);
}
