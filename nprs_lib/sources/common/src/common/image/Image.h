#ifndef COMMON_IMAGE_H
#define COMMON_IMAGE_H

#include <vector>
#include "Color.h"
#include <common/Rectangle.h>

using uchar = unsigned char;

namespace nprs {

class Image final {
public:
    Image(int width, int height, ColorInfo colorInfo);
    Image(const Image &other);

    Image(Image && other);
    Image& operator= (Image && other);

    float getValue(int x, int y, int c) const;
    float& operator() (int x, int y, int c);
    float const& operator() (int x, int y, int c) const;
    void setValue(int x, int y, int c, float value);

    int width() const { return _width; }
    int height() const { return _height; }
    const ColorInfo & colorInfo() const { return _colorInfo; }
    const std::vector<float> & data() { return _data; }

    Image resized(int width, int height) const;
    Image cropped(int x, int y, int width, int height) const;
    Image cropped(const Rectangle &rect) const;
    Image copyChannel(int c) const;
    bool isInside(int x, int y) const;

private:
    int _width;
    int _height;
    std::vector<float> _data;
    ColorInfo _colorInfo;

    int ind(int x, int y, int channel) const { return (y * _width + x) * _colorInfo.numChannels() + channel; }
};

#include "Image.inl"

}

#endif // COMMON_IMAGE_H
