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

private:
    sp<const Image> _image;
    int _numSamples;
    Size _minSize;
    Size _maxSize;

    up<SampleExtractor> createLightSampleExtractor() const override;
    up<SampleExtractor> createHeavySampleExtractor() const override;
};

}

#endif // TRAININGLIB_NEGATIVESCENEINPUTSAMPLE_H
