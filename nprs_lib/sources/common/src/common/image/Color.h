#ifndef COMMON_COLOR_H
#define COMMON_COLOR_H

namespace nprs {

enum class ColorFormat {
    RGB, INT, LUM, RGBA, BGRA
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