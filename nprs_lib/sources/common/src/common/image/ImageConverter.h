#ifndef COMMON_IMAGECONVERTER_H
#define COMMON_IMAGECONVERTER_H

#include "Image.h"
#include <memory>

namespace nprs {

template <typename T> class Image;

class ImageConverter {
public:
    static void bgraByte255ToLumFloat1(Image<float> &result, const Image<uchar> &image);
    static void rgbaByte255ToLumFloat1(Image<float> &result,const Image<uchar> &image);
    static Image<uchar> bgraByte255ToLumByte255(const Image<uchar> &image);
};

}

#endif // COMMON_IMAGECONVERTER_H
