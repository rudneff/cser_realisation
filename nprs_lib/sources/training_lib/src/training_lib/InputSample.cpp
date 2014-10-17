#include "InputSample.h"

#include "SampleExtractor.h"
#include "Sample.h"

namespace nprs {

InputSample::~InputSample() {
}

std::vector<Sample> InputSample::extractNMLightSamples() const {
    sp<SampleExtractor> extractor = createExtractor();
    return extractor->extractNMLightSamples();
}

std::vector<Sample> InputSample::extractNMHeavySamples() const {
    sp<SampleExtractor> extractor = createExtractor();
    return extractor->extractNMHeavySamples();
}

}
