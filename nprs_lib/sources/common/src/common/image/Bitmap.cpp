#include "Bitmap.h"
#include <memory>
#include <iostream>

using namespace nprs;

Bitmap::Bitmap(int width, int height, const ColorInfo &colorInfo) 
    : _width(width),
      _height(height),
      _colorInfo(colorInfo),
      _dataSize(width * height * colorInfo.numChannels())
{
    _data = new uchar[_dataSize];
}

Bitmap::Bitmap(const uchar *data, int width, int height, const ColorInfo &colorInfo)
    : _width(width), 
      _height(height), 
      _colorInfo(colorInfo),
      _dataSize(width * height * colorInfo.numChannels())
{
    _data = new uchar[_dataSize];
    std::copy(data, data + _dataSize, _data);
}

Bitmap::Bitmap(const Bitmap &that)
    : _data(nullptr),
      _width(that._width),
      _height(that._height),
      _colorInfo(that._colorInfo)
{
    _dataSize = that._width * that._height * that._colorInfo.numChannels();
    _data = new uchar[_dataSize];
    std::copy(that._data, that._data + _dataSize, _data);
}

Bitmap::Bitmap(Bitmap && that) 
    : _data(that._data),
      _width(that._width),
      _height(that._height),
      _colorInfo(that._colorInfo),
      _dataSize(that._dataSize)
{
    that._data = nullptr;
}

Bitmap::~Bitmap() {
    if (_data != nullptr)
        delete[] _data;
}

Bitmap& Bitmap::operator=(const Bitmap &that) {
    if (this != &that) {
        _width = that._width;
        _height = that._height;
        _colorInfo = that._colorInfo;
        _dataSize = that._dataSize;

        _data = new uchar[_dataSize];
        std::copy(that._data, that._data + _dataSize, _data);
    }
    return *this;
}

Bitmap& Bitmap::operator=(Bitmap && that) {
    if (this != &that) {
        _width = that._width;
        _height = that._height;
        _colorInfo = that._colorInfo;
        _data = that._data;
        _dataSize = that._dataSize;
        that._data = nullptr;
    }
    return *this;
}
