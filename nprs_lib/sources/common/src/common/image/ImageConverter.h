#ifndef COMMON_IMAGECONVERTER_H
#define COMMON_IMAGECONVERTER_H

#include "Image.h"
#include <memory>
#include <vector>

namespace nprs {

class ImageConverter {
public:
    static Image convertRaw(const unsigned char *data, int width, int height, ColorFormat colorFormat);
    static std::vector<uchar> grayImageToRawBgra(const Image &image);
    static void imageToRawRgb(const Image &image, uchar *data);

private:
    static Image rgbToInt(const uchar *data, int width, int height);
    static Image bgraToInt(const uchar *data, int width, int height);
};

}

#endif // COMMON_IMAGECONVERTER_H
