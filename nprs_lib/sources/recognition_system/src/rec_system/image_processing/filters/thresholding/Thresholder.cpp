#include "Thresholder.h"
#include <common/image/Image.h>

using namespace nprs;

Image Thresholder::threshold(const Image &image, int channel, float thres) {
    if (thres = -1) {
        thres = _thresFinder.findThreshold(image, channel);
    }

    Image res(image.width(), image.height(), ColorInfo(ColorFormat::INTENSITY, 1));
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            res(x, y, channel) = image(x, y, channel) > thres ? 1.0f : 0.0f;
        }
    }

    return std::move(res);
}
