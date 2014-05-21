#ifndef COMMON_IMAGECONVERTER_H
#define COMMON_IMAGECONVERTER_H

#include "Image.h"
#include <memory>

namespace nprs {

template <typename T> using pImage = std::shared_ptr<Image<T> >;

class ImageConverter {
public:
    static pImage<float> bgraByte255ToLumFloat1(const pImage<uchar> &image);
    static pImage<float> rgbaByte255ToLumFloat1(const pImage<uchar> &image);
};

}

#endif // COMMON_IMAGECONVERTER_H
