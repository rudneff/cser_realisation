#include "PositiveImageInputSample.h"
#include <training_lib/input_sample_extractors/AutoThresholdExtractor.h>
#include <training_lib/input_sample_extractors/HogSampleExtractor.h>

namespace nprs {

PositiveImageInputSample::PositiveImageInputSample(sp<const Image> image)
    : ImageInputSample(image)
{
}

up<SampleExtractor> nprs::PositiveImageInputSample::createLightSampleExtractor() const {
    return up<SampleExtractor>(new AutoThresholdExtractor(image()));
}

up<SampleExtractor> PositiveImageInputSample::createHeavySampleExtractor() const {
    return up<SampleExtractor>(new HogSampleExtractor(image()));
}

}
