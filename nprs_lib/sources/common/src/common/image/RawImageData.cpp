#include "RawImageData.h"
#include <memory>
#include <iostream>

using namespace nprs;

RawImageData::RawImageData(uchar *data, int width, int height, const ColorInfo &colorInfo)
    : _width(width), 
      _height(height), 
      _colorInfo(colorInfo) 
{
    int size = width * height * colorInfo.numChannels();
    _data = new uchar[size];
    std::copy(data, data + size, _data);
}

RawImageData::RawImageData(const RawImageData &that)
    : _data(nullptr),
      _width(that._width),
      _height(that._height),
      _colorInfo(that._colorInfo)
{
    int size = that._width * that._height * that._colorInfo.numChannels();
    _data = new uchar[size];
    std::copy(that._data, that._data + size, _data);
}

RawImageData::RawImageData(RawImageData && that) 
    : _data(that._data),
      _width(that._width),
      _height(that._height),
      _colorInfo(that._colorInfo),
      _dataSize(that._dataSize)
{
    that._data = nullptr;
}

RawImageData::~RawImageData() {
    if (_data != nullptr)
        delete[] _data;
}

RawImageData& RawImageData::operator=(const RawImageData &that) {
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

RawImageData& RawImageData::operator=(RawImageData && that) {
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
