#ifndef COMMON_COLOR_H
#define COMMON_COLOR_H

namespace nprs {

enum ColorFormat {
    COLORFORMAT_RGB, COLORFORMAT_RGB_NORM, COLORFORMAT_GRAY, COLORFORMAT_GRAY_NORM
};

class ColorInfo {
public:
    ColorInfo(ColorFormat format, int numChannels)
        : _format(format), _numChannels(numChannels)
    {}

    int numChannels() { return _numChannels; }
    ColorFormat format() { return _format; }

private:
    int _numChannels;
    ColorFormat _format;
};

}

#endif