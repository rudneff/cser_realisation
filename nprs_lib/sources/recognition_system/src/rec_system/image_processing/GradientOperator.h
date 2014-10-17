#include <common/image/Image.h>

#ifndef RS_GRADIENTOPERATOR_H
#define RS_GRADIENTOPERATOR_H

namespace nprs {

class Image;
class Rectangle;

class GradientOperator {
public:
    virtual ~GradientOperator() {}

    inline Image performUnbounded(const Image &inputImage, int channel);

    /**
    * returns Image with 4 channels:
    *   0 - gx
    *   1 - gy
    *   2 - magnitude
    *   3 - atan2(gy, gx)
    */
    virtual Image perform(const Image &inputImage, int channel, const Rectangle &bounds) const = 0;
};




// --------------- Inline definitions -----------------------------------------------------------------

inline Image GradientOperator::performUnbounded(const Image &inputImage, int channel) {
    return perform(inputImage, channel, Rectangle(0, 0, inputImage.width(), inputImage.height()));
}

}

#endif // RS_GRADIENTOPERATOR_H
