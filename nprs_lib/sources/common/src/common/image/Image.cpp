#include "Image.h"
#include <iostream>
#include <common/exceptions/ArgumentException.h>

using namespace nprs;

Image::Image(int width, int height, ColorInfo colorInfo)
    : _width(width), 
      _height(height), 
      _colorInfo(colorInfo),
      _data(width * height * colorInfo.numChannels())
{
}

Image::Image(const Image &other) 
    : _width(other._width),
      _height(other._height),
      _colorInfo(other._colorInfo),
      _data(other._data)
{
}

Image::Image(Image && other)
    : _width(other._width),
      _height(other._height),
      _colorInfo(other._colorInfo),
      _data(std::move(other._data))
{
}
Image& Image::operator=(Image&& other) {
    if (this != &other) {
        _width = other._width;
        _height = other._height;
        _colorInfo = other._colorInfo;
        _data = std::move(other._data);
    }

    return *this;
}

Image Image::resized(int width, int height) const {
    float asp = _width / (float)_height;
    Image res(width = asp * height, height, _colorInfo);

    float kx = _width / (float) width;
    float ky = _height / (float) height;

    for (int x = 0; x < res.width(); x++) {
        for (int y = 0; y < res.height(); y++) {
            for (int c = 0; c < _colorInfo.numChannels(); c++) {
                int ox = x * kx;
                int oy = y * ky;
                res(x, y, c) = getValue(ox, oy, c);
            }
        }
    }

    return res;
}

Image Image::cropped(int x0, int y0, int width, int height) const {
    Image res(width, height, _colorInfo);

    if (!isInside(x0, y0) || !isInside(x0 + width - 1, y0 + height - 1)) {
        throw ArgumentException("Image::cropped: rectangle is out of image bounds");
    }
    
    for (int x = x0; x < x0 + width; x++) {
        for (int y = y0; y < y0 + height; y++) {
            for (int c = 0; c < _colorInfo.numChannels(); c++) {
                res(x - x0, y - y0, c) = getValue(x, y, c);
            }
        }
    }

    return res;
}
