#include <common/image/Image.h>
#include "IntensityRescaleFilter.h"

namespace nprs {

IntensityRescaleFilter::IntensityRescaleFilter(float rangeMin, float rangeMax)
    : _rangeMin(rangeMin),
      _rangeMax(rangeMax)
{

}

void IntensityRescaleFilter::applyChannel(Image &outImage, int outChannel, const Image &inImage, int inChannel) {
    float rangeMin, rangeMax;
    inImage.computeRange(&rangeMin, &rangeMax, inChannel);
    for (int x = 0; x < inImage.width(); x++) {
        for (int y = 0; y < inImage.height(); y++) {
            outImage(x, y, outChannel) = (inImage(x, y, inChannel) - rangeMin) / (rangeMax - rangeMin);
        }
    }
}

}
