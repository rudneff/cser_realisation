#include "SimpleGradientOperator.h"
#include <common/image/Image.h>
#include <common/math/Math.h>
#include <rec_system/image_processing/filters/IntensityRescaleFilter.h>

namespace nprs {

Image SimpleGradientOperator::perform(const Image &inputImage, int channel, const Rectangle &bounds) const {
    Image resultImage(inputImage.width(), inputImage.height(), ColorInfo(ColorFormat::INTENSITY, 4));
    for (int x = (int) bounds.x(); x < bounds.x1(); x++) {
        for (int y = (int) bounds.y(); y < bounds.y1(); y++) {
            float rx = inputImage.isInside(x + 1, y) ? inputImage(x + 1, y, channel) : 0.0f;
            float lx = inputImage.isInside(x - 1, y) ? inputImage(x - 1, y, channel) : 0.0f;
            float ty = inputImage.isInside(x, y - 1) ? inputImage(x, y - 1, channel) : 0.0f;
            float by = inputImage.isInside(x, y + 1) ? inputImage(x, y + 1, channel) : 0.0f;

            float gx = -lx + rx;
            float gy = -ty + by;

            resultImage(x, y, 0) = gx;
            resultImage(x, y, 1) = gy;
            resultImage(x, y, 2) = (float) Math::sqrt(gx * gx + gy * gy);
            resultImage(x, y, 3) = Math::atan2(gy, gx);
        }
    }

    IntensityRescaleFilter rsFilter(0, 1);
    return rsFilter.apply(resultImage, 2);
}

}
