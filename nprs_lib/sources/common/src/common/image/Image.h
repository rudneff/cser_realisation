#ifndef COMMON_IMAGE_H
#define COMMON_IMAGE_H

#include <vector>
#include "Color.h"

using uchar = unsigned char;

namespace nprs {

class Image final {
public:
    Image(int width, int height, ColorInfo colorInfo);
    
    float getValue(int x, int y, int c) const { return _data[ind(x, y, c)]; }
    float& operator() (int x, int y, int c) { return _data[ind(x, y, c)]; }
    float operator() (int x, int y, int c) const { return _data[ind(x, y, c)]; }
    float setValue(int x, int y, int c, float value) { _data[ind(x, y, c)] = value; }

    int width() const { return _width; }
    int height() const { return _height; }

    const ColorInfo& colorInfo() const { return _colorInfo; }
    const std::vector<float> & data() { return _data; }

private:
    int _width;
    int _height;
    int _bytesPerValue;
    std::vector<float> _data;
    ColorInfo _colorInfo;

    int ind(int x, int y, int channel) const { return (y * _width + x) * _colorInfo.numChannels() + channel; }
};

}

#endif // COMMON_IMAGE_H
