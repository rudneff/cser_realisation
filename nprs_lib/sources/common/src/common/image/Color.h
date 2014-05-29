#ifndef COMMON_COLOR_H
#define COMMON_COLOR_H

namespace nprs {

enum ColorFormat {
    COLORFORMAT_RGB255,
    COLORFORMAT_I255,
    COLORFORMAT_BGRA255,
    COLORFORMAT_RGB1,
    COLORFORMAT_I1,
    COLORFORMAT_BGRA1
};

class ColorInfo {
public:
    ColorInfo(ColorFormat format, int numChannels)
        : _format(format), _numChannels(numChannels)
    {}

    int numChannels() const { return _numChannels; }
    ColorFormat format() const { return _format; }

private:
    int _numChannels;
    ColorFormat _format;
};

}

#endif