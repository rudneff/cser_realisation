#ifndef COMMON_RAWIMAGEDATA_H
#define COMMON_RAWIMAGEDATA_H

#include "Color.h"

using uchar = unsigned char;

namespace nprs {

class RawImageData {
public:
    RawImageData(const uchar *data, int width, int height, ColorInfo colorInfo)
        : _data(data), _width(width), _height(height), _colorInfo(colorInfo)
    {}

    const uchar * data() const{ return _data; }
    int width() const { return _width; }
    int height() const { return _height; }
    ColorInfo colorInfo() const { return _colorInfo; }

private:
    const uchar *_data;
    int _width;
    int _height;
    ColorInfo _colorInfo;
};

}

#endif // COMMON_RAWIMAGEDATA_H
