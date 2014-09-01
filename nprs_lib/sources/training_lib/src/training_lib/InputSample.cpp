#include "InputSample.h"

#include "SampleExtractor.h"
#include "Sample.h"

namespace nprs {

InputSample::~InputSample() {
}

std::vector<Sample> InputSample::extractNMLightSamples() const {
    auto extractor = createExtractor();
    return extractor->extractNMLightSamples();
}

}
