#ifndef COMMON_IMAGE_H
#define COMMON_IMAGE_H

#include <vector>
#include "Color.h"

using uchar = unsigned char;

namespace nprs {

template <typename TPix>
class Image {
public:
    Image(const TPix *data, int width, int height, const ColorInfo &colorInfo)
        : _width(width), _height(height), _channels(colorInfo.numChannels()), _colorInfo(colorInfo), _data(width * height * colorInfo.numChannels())
    {
        std::memcpy(&_data[0], data, width * height * colorInfo.numChannels() * sizeof(TPix));
    }

    Image(int width, int height, const ColorInfo &colorInfo)
        : _width(width), _height(height), _colorInfo(colorInfo), _channels(colorInfo.numChannels()), _data(width * height * colorInfo.numChannels())
    {
    }

    TPix & operator() (int x, int y, int channel) {
        return _data[(y * _width + x) * _channels + channel];
    }

    TPix operator() (int x, int y, int channel) const {
        return _data[(y * _width + x) * _channels + channel];
    }

    TPix getValue(int x, int y, int channel) const {
        return _data[(y * _width + x) * _channels + channel];
    }

    void setValue(int x, int y, int channel, TPix value) {
        _data[(y * _width + x) * _channels + channel] = value;
    }

    int width() const { return _width; }
    int height() const { return _height; }
    ColorInfo const& getColorInfo() const { return _colorInfo; }

private:
    ColorInfo _colorInfo;
    std::vector<TPix> _data;

    int _width;
    int _height;
    int _channels;

    int mapCoord(int x, int y) const {
        return (y * _width + x) * _channels;
    }
};

}

#endif