#include "InputSample.h"

#include "SampleExtractor.h"
#include "Sample.h"

namespace nprs {

InputSample::~InputSample() {
}

std::vector<Sample> InputSample::extractNMLightSamples() const {
    sp<SampleExtractor> extractor = createLightSampleExtractor();
    return extractor->extractSamples();
}

std::vector<Sample> InputSample::extractNMHeavySamples() const {
    sp<SampleExtractor> extractor = createHeavySampleExtractor();
    return extractor->extractSamples();
}

}
