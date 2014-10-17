#ifndef RS_MASKFILTER_H
#define RS_MASKFILTER_H

#include <rec_system/image_processing/filters/ImageFilter.h>
#include <common/Matrix.h>

namespace nprs {

class Image;
    
class MaskFilter : public ImageFilter {
public:
    explicit MaskFilter(const Matrix<float> &mask);

    virtual void applyChannel(Image &outImage, int outChannel, const Image &inImage, int inChannel);

private:
    Matrix<float> _mask;

    void normalizeMask();
};

}

#endif // RS_MASKFILTER_H
