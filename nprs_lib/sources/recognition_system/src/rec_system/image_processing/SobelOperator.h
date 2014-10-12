#ifndef RS_SOBELOPERATOR_H
#define RS_SOBELOPERATOR_H

#include <common/NprsStd.h>
#include <rec_system/image_processing/filters/MaskFilter.h>

namespace nprs {

class Image;
class MaskFilter;
    
class SobelOperator {
public:
    SobelOperator();

    Image apply(const Image &image) const;

private:
    up<MaskFilter> _gxFilter;
    up<MaskFilter> _gyFilter;
};

}

#endif // RS_SOBELOPERATOR_H
