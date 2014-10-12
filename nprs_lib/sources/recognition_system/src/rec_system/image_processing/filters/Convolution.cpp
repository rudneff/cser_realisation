#include "Convolution.h"
#include <common/image/Image.h>

namespace nprs {

static float convolvePixel(const Image &src, int x, int y, int c, Matrix<float> const& mask);
    
Image convolveImage(Image const& src, Matrix<float> const& mask) {
    Image result(src.width(), src.height(), src.colorInfo());
    for (int x = 0; x < src.width(); x++) {
        for (int y = 0; y, y < src.height(); y++) {
            for (int c = 0; c < src.colorInfo().numChannels(); c++) {
                result(x, y, c) = convolvePixel(src, x, y, c, mask);
            }
        }
    }

    return result;
}

static float convolvePixel(Image const& src, int x, int y, int c, Matrix<float> const& mask) {
    const int maskSize = mask.width();
    const int maskMid = maskSize / 2;
    float res = 0.0f;
    for (int qx = -maskSize / 2; qx <= maskSize / 2; qx++) {
        for (int qy = - maskSize / 2; qy <= maskSize / 2; qy++) {
            int mx = maskMid + qx;
            int my = maskMid + qy;
            int px = x + qx;
            int py = y + qy;

            if (src.isInside(px, py))
                res += src(px, py, c) * mask(mx, my);
        }
    }

    return res;
}

}
