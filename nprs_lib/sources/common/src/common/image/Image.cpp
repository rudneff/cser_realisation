#include "Image.h"

using namespace nprs;

Image::Image(int width, int height, ColorInfo colorInfo)
    : _width(width), 
      _height(height), 
      _colorInfo(colorInfo),
      _data(width * height * colorInfo.numChannels())
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
