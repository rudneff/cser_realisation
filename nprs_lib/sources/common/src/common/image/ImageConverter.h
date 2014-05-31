#ifndef COMMON_IMAGECONVERTER_H
#define COMMON_IMAGECONVERTER_H

#include "Image.h"
#include <memory>

namespace nprs {

template <typename T> class Image;

class ImageConverter {
public:
    static Image<uchar> toLum255(const Image<uchar> &image);
    static Image<uchar> toInt255(const Image<uchar> &image);

private:
    static Image<uchar> rgbToLum255(const Image<uchar> &image);
    static Image<uchar> bgraToLum255(const Image<uchar> &image);
};

}

#endif // COMMON_IMAGECONVERTER_H
