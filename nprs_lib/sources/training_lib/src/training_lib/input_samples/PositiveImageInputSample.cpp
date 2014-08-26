#include "PositiveImageInputSample.h"
#include <training_lib/input_sample_extractors/AutoThresholdExtractor.h>

using namespace nprs;


PositiveImageInputSample::PositiveImageInputSample(sp<const Image> image)
    : ImageInputSample(image) 
{
}

sp<SampleExtractor> nprs::PositiveImageInputSample::createExtractor() const {
    return make_shared<AutoThresholdExtractor>(image());
}
