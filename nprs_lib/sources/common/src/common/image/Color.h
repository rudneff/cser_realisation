#ifndef COMMON_COLOR_H
#define COMMON_COLOR_H

namespace nprs {

enum class ColorFormat {
    RGB255, I255, BGRA255, RGB1, I1, BGRA1
};


class Color {
public:
    
private:
    
};

class ColorInfo {
public:
    static ColorInfo RgbByte255();
    static ColorInfo BgraByte255();

public:
    ColorInfo(ColorFormat format, int numChannels, int bytesPerPixel)
        : _format(format), _numChannels(numChannels), _bpp(bytesPerPixel)
    {}

    int numChannels() const { return _numChannels; }
    ColorFormat format() const { return _format; }
    int bytesPerPixel() const { return _bpp; }

private:
    int _numChannels;
    ColorFormat _format;
    int _bpp;
};

}

#endif