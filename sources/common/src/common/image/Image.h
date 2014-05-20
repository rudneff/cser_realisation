#ifndef COMMON_IMAGE_H
#define COMMON_IMAGE_H

#include <vector>
#include "Color.h"

namespace nprs {

template <typename TPix>
class Image {
public:
    Image(const TPix *data, int width, int height, int nChannels, ColorInfo colorInfo)
    {
        
    }

    Image(int width, int height, ColorInfo colorInfo)
        : _width(width), _height(height), _colorInfo(colorInfo), _channels(colorInfo.numChannels())
    {}

    TPix getValue(int x, int y, int channel) const {
        return _data[(y * _width + x) * _channels + channel];
    }

    void setValue(int x, int y, int channel, TPix value) {
        _data[(y * _width + x) * _channels + channel] = value;
    }

    int width() const { return _width; }
    int height() const { return _height; }

private:
    ColorInfo _colorInfo;
    TPix *_data;

    int _width;
    int _height;
    int _channels;

    int mapCoord(int x, int y) const {
        return (y * _width + x) * _channels;
    }
};

}

#endif