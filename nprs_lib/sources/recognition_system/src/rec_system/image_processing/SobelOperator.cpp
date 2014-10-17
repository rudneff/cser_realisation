#include "SobelOperator.h"
#include <common/image/Image.h>
#include <common/math/Math.h>
#include <common/image/Color.h>
#include <rec_system/image_processing/filters/IntensityRescaleFilter.h>

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

Image SobelOperator::perform(Image const& image, int channel, const Rectangle &bounds) const {
    Image result(image.width(), image.height(), ColorInfo(ColorFormat::INTENSITY, 4));
    Image gx = _gxFilter->apply(image, channel);
    Image gy = _gyFilter->apply(image, channel);

    for (int x = (int) bounds.x(); x < bounds.x1(); x++) {
        for (int y = (int) bounds.y(); y < bounds.y1(); y++) {
            result(x, y, 0) = gx(x, y, 0);
            result(x, y, 1) = gy(x, y, 0);
            result(x, y, 2) = (float) (Math::sqrt(Math::sqr(gx(x, y, 0)) + Math::sqr(gy(x, y, 0))));
            result(x, y, 3) = Math::atan2(gy(x, y, 0), gx(x, y, 0));
//            std::cout << "[" << x << ", " << y << "]" << " --- " << gx(x, y, 0) << "  " << gy(x, y, 0) << "  " << result(x, y, 2) << result(x, y, 3) << std::endl;
        }
    }

    IntensityRescaleFilter rsFilter(0, 1);
    return rsFilter.apply(result, 2);
}

}
