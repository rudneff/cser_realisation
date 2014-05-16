#ifndef COMMON_COLOR_H
#define COMMON_COLOR_H

namespace nprs {

enum ColorFormat {
    RGB, RGB_NORM, GRAY, GRAY_NORM
};

class ColorInfo {
public:
    int numChannels() { return _numChannels; }
    ColorFormat format() { return _format; }

private:
    int _numChannels;
    ColorFormat _format;
};

}

#endif