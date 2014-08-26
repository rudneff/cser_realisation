#ifndef TRAININGLIB_NEGATIVESCENEINPUTSAMPLE_H
#define TRAININGLIB_NEGATIVESCENEINPUTSAMPLE_H

#include "ImageInputSample.h"

namespace nprs {

class NegativeImageInputSample : public ImageInputSample {
public: 
    NegativeImageInputSample(sp<const Image> image, int numSamples);

    sp<SampleExtractor> createExtractor() const override;

private:
    sp<const Image> _image;
    int _numSamples;
};

}

#endif // TRAININGLIB_NEGATIVESCENEINPUTSAMPLE_H
