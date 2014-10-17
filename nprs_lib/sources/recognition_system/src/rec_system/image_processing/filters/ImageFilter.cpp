#include <common/image/Image.h>
#include "ImageFilter.h"

namespace nprs {

Image ImageFilter::apply(const Image &origin) {
    Image result(origin.width(), origin.height(), origin.colorInfo());
    for (int channel = 0; channel < origin.colorInfo().numChannels(); channel++) {
        applyChannel(result, channel, origin, channel);
    }

    return result;
}

Image ImageFilter::apply(const Image &origin, int channel) {
    Image result(origin);
    applyChannel(result, channel, origin, channel);
    return result;
}

}
