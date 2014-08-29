#ifndef TRAININGLIB_NEGATIVESCENEINPUTSAMPLE_H
#define TRAININGLIB_NEGATIVESCENEINPUTSAMPLE_H

#include "ImageInputSample.h"
#include <common/Size.h>

namespace nprs {

class NegativeImageInputSample : public ImageInputSample {
public: 
    NegativeImageInputSample(
        sp<const Image> image,
        int numSamples,
        const Size &minRegionSize,
        const Size &maxRegionSize);

    sp<SampleExtractor> createExtractor() const override;

private:
    sp<const Image> _image;
    int _numSamples;
    Size _minSize;
    Size _maxSize;
};

}

#endif // TRAININGLIB_NEGATIVESCENEINPUTSAMPLE_H
