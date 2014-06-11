#ifndef COMMON_RAWIMAGEDATA_H
#define COMMON_RAWIMAGEDATA_H

#include "Color.h"

using uchar = unsigned char;

namespace nprs {

class Bitmap final {
public:
    Bitmap(int width, int height, const ColorInfo &colorInfo);
    Bitmap(const uchar *data, int width, int height, const ColorInfo &colorInfo);
    Bitmap(const Bitmap &that);
    Bitmap(Bitmap && that);
    ~Bitmap();

    Bitmap & operator= (const Bitmap &that);
    Bitmap & operator= (Bitmap && that);

    const uchar * data() const { return _data; }
    uchar * data() { return _data; }
    int width() const { return _width; }
    int height() const { return _height; }
    const ColorInfo & colorInfo() const { return _colorInfo; }

private:
    uchar *_data;
    int _width;
    int _height;
    int _dataSize;
    ColorInfo _colorInfo;
};

}

#endif // COMMON_RAWIMAGEDATA_H
