#include "PositiveImageInputSample.h"
#include <training_lib/input_sample_extractors/AutoThresholdExtractor.h>

using namespace nprs;


PositiveImageInputSample::PositiveImageInputSample(sp<const Image> image)
    : ImageInputSample(image) 
{
}

up<SampleExtractor> nprs::PositiveImageInputSample::createExtractor() const {
    return up<AutoThresholdExtractor>(new AutoThresholdExtractor(image()));
}
