#ifndef RS_INTENSITYRESCALEFILTER_H
#define RS_INTENSITYRESCALEFILTER_H

#include "ImageFilter.h"

namespace nprs {

class IntensityRescaleFilter: public ImageFilter {
public:
    IntensityRescaleFilter(float rangeMin, float rangeMax);

    virtual void applyChannel(Image &outImage, int outChannel, const Image &inImage, int inChannel);

private:
    float _rangeMin;
    float _rangeMax;
};

}

#endif // RS_INTENSITYRESCALEFILTER_H
