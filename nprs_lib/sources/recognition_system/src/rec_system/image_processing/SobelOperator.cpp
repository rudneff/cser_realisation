#include "SobelOperator.h"

#include <common/image/Image.h>
#include <common/math/Math.h>
#include <common/image/Color.h>

//#include <iostream>

namespace nprs {

SobelOperator::SobelOperator()
{
    Matrix<float> gxMask = std::vector<std::vector<float>>(
        {{-1, -2, -1},
         { 0,  0,  0},
         { 1,  2,  1}});

    Matrix<float> gyMask = std::vector<std::vector<float>>(
        {{-1, 0, 1},
         {-2, 0, 2},
         {-1, 0, 1}});

    _gxFilter = up<MaskFilter>(new MaskFilter(gxMask));
    _gyFilter = up<MaskFilter>(new MaskFilter(gyMask));
}

Image SobelOperator::apply(Image const& image) const {
    Image result(image.width(), image.height(), ColorInfo(ColorFormat::INTENSITY, 4));
    Image gx = _gxFilter->apply(image);
    Image gy = _gxFilter->apply(image);

    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            result(x, y, 0) = gx(x, y, 0);
            result(x, y, 1) = gy(x, y, 0);
            result(x, y, 2) = Math::sqrt(Math::sqr(gx(x, y, 0)) * Math::sqr(gy(x, y, 0)));
            result(x, y, 3) = Math::atan(gy(x, y, 0) / gx(x, y, 0));
//            std::cout << "[" << x << ", " << y << "]" << " --- " << gx(x, y, 0) << "  " << gy(x, y, 0) << "  " << result(x, y, 2) << result(x, y, 3) << std::endl;
        }
    }

    return result;
}

}
