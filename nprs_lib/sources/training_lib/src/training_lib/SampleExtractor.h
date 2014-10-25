#ifndef TRAININGLIB_SYMBOLEXTRACTOR_H
#define TRAININGLIB_SYMBOLEXTRACTOR_H

#include <common/NprsStd.h>
#include <tuple>
#include <vector>
#include "Sample.h"

namespace nprs {

class InputSample;

class SampleExtractor {
public:
    SampleExtractor();
    virtual ~SampleExtractor();

    virtual std::vector<Sample> extractSamples() = 0;
};

}

#endif // TRAININGLIB_SYMBOLEXTRACTOR_H
