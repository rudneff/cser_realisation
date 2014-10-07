#ifndef RECSYSTEM_THRESHOLDER_H
#define RECSYSTEM_THRESHOLDER_H

#include "OtsuThresholder.h"

namespace nprs {

class Image;

class Thresholder {
public:
    Image threshold(const Image &image, int channel = 0, float thres = -1);

private:
    OtsuThresholder _thresFinder;
};

}

#endif // RECSYSTEM_THRESHOLDER_H
