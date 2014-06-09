#ifndef COMMON_IMAGECONVERTER_H
#define COMMON_IMAGECONVERTER_H

#include "Image.h"
#include <memory>
#include <vector>
#include <common/image/RawImageData.h>

namespace nprs {

class ImageConverter {
public:
    static Image convertRaw(const RawImageData &raw);
    static std::vector<uchar> imageToRawBgra(const Image &image);
    static std::vector<uchar> imageToRawRgb(const Image &image);

private:
    static Image rgbToInt(const uchar *data, int width, int height);
    static Image bgraToInt(const uchar *data, int width, int height);
    static Image rgbaToInt(const uchar* data, int width, int height);
};

}

#endif // COMMON_IMAGECONVERTER_H
