#ifndef RS_SOBELOPERATOR_H
#define RS_SOBELOPERATOR_H

#include <common/NprsStd.h>
#include <rec_system/image_processing/filters/MaskFilter.h>
#include "GradientOperator.h"

namespace nprs {

class Image;
class MaskFilter;
    
class SobelOperator: public GradientOperator {
public:
    SobelOperator();

    virtual Image perform(const Image &image, int channel, const Rectangle &bounds) const override;

private:
    up<MaskFilter> _gxFilter;
    up<MaskFilter> _gyFilter;
};

}

#endif // RS_SOBELOPERATOR_H
