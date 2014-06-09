#ifndef COMMON_RAWIMAGEDATA_H
#define COMMON_RAWIMAGEDATA_H

#include "Color.h"

using uchar = unsigned char;

namespace nprs {

class RawImageData final {
public:
    RawImageData(uchar *data, int width, int height, const ColorInfo &colorInfo);
    RawImageData(const RawImageData &that);
    RawImageData(RawImageData && that);
    ~RawImageData();

    RawImageData & operator= (const RawImageData &that);
    RawImageData & operator= (RawImageData && that);

    const uchar * data() const{ return _data; }
    int width() const { return _width; }
    int height() const { return _height; }
    ColorInfo colorInfo() const { return _colorInfo; }

private:
    uchar *_data;
    int _width;
    int _height;
    int _dataSize;
    ColorInfo _colorInfo;
};

}

#endif // COMMON_RAWIMAGEDATA_H
