#ifndef TRAININGLIB_SYMBOLEXTRACTOR_H
#define TRAININGLIB_SYMBOLEXTRACTOR_H

#include <common/NprsStd.h>
#include <tuple>
#include <vector>

namespace nprs {

class Sample;
class InputSample;

class SampleExtractor {
public:
    SampleExtractor();
    virtual ~SampleExtractor();

    virtual std::vector<Sample> extractNMLightSamples() = 0;
};

}

#endif // TRAININGLIB_SYMBOLEXTRACTOR_H
