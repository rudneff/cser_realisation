#include "MaskFilter.h"
#include <common/image/Image.h>
#include <common/exceptions/CommonExceptions.h>
#include <rec_system/image_processing/filters/Convolution.h>
#include <common/math/Math.h>

namespace nprs {

MaskFilter::MaskFilter(Matrix<float> const& mask) 
: _mask(mask)
{
//    normalizeMask();
}

void MaskFilter::normalizeMask() {
    float sum = 0.0f;
    for (int x = 0; x < _mask.width(); x++) {
        for (int y = 0; y < _mask.height(); y++) {
            sum += Math::abs(_mask(x, y));
        }
    }

    for (int x = 0; x < _mask.width(); x++) {
        for (int y = 0; y < _mask.height(); y++) {
            _mask(x, y) /= sum;
        }
    }
}

void MaskFilter::applyChannel(Image &outImage, int outChannel, const Image &inImage, int inChannel) {
    convolveChannel(outImage, outChannel, inImage, inChannel, _mask);
}

}
