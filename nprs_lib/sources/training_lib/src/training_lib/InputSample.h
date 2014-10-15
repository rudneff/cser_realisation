#ifndef TRAININGLIB_INPUTSAMPLE_H
#define TRAININGLIB_INPUTSAMPLE_H

#include <common/NprsStd.h>
#include <vector>
#include "Sample.h"

namespace nprs {

class SampleExtractor;
class Sample;

class InputSample {
public:
    virtual ~InputSample();

    std::vector<Sample> extractNMLightSamples() const;
    std::vector<Sample> extractNMHeavySamples() const;

private:
    virtual up<SampleExtractor> createExtractor() const = 0;
};

}

#endif // TRAININGLIB_INPUTSAMPLE_H
