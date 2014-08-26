#ifndef SYMBOL_FEATURE_EXTRACTOR_H
#define SYMBOL_FEATURE_EXTRACTOR_H

#include <common/NprsStd.h>
#include <tuple>
#include <vector>

namespace nprs {

class Sample;
class InputSample;

class SampleExtractor {
public:
    SampleExtractor();
    virtual ~SampleExtractor() {}

    virtual std::vector<Sample> extractNMLightSamples() = 0;
};

}

#endif // SYMBOL_FEATURE_EXTRACTOR_H
