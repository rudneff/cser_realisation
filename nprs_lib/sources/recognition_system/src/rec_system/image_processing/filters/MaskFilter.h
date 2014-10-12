#ifndef RS_MASKFILTER_H
#define RS_MASKFILTER_H

#include <rec_system/image_processing/filters/ImageFilter.h>
#include <common/Matrix.h>
#include <common/Point.h>

namespace nprs {
    
class MaskFilter : ImageFilter {
public:
    explicit MaskFilter(const Matrix<float> &mask);

    Image apply(Image const& origin) override;

private:
    Matrix<float> _mask;

    void normalizeMask();
};

}

#endif // RS_MASKFILTER_H
