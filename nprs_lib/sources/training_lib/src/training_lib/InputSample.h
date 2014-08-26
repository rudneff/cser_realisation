#ifndef TRAININGLIB_INPUTSAMPLE_H
#define TRAININGLIB_INPUTSAMPLE_H

#include <common/NprsStd.h>

namespace nprs {

class SampleExtractor;

class InputSample {
public:
    virtual ~InputSample() {}
    virtual sp<SampleExtractor> createExtractor() const = 0;
};

}

#endif // TRAININGLIB_INPUTSAMPLE_H
