#include "Convolution.h"
#include <common/image/Image.h>

namespace nprs {

static float convolvePixel(const Image &src, int x, int y, int c, Matrix<float> const& mask);
    
Image convolveImage(Image const& src, Matrix<float> const& mask) {
    Image result(src.width(), src.height(), src.colorInfo());

    for (int channel = 0; channel < src.colorInfo().numChannels(); channel++) {
        convolveChannel(result, channel, src, channel, mask);
    }

    return result;
}

void convolveChannel(
    Image &outImage,
    int outChannel,
    const Image &inImage,
    int inChannel,
    const Matrix<float> &mask)
{
    for (int x = 0; x < inImage.width(); x++) {
        for (int y = 0; y, y < inImage.height(); y++) {
                outImage(x, y, outChannel) = convolvePixel(inImage, x, y, inChannel, mask);
        }
    }
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
