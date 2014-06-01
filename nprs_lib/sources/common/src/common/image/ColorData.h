#ifndef COMMON_COLORDATA_H
#define COMMON_COLORDATA_H

namespace nprs {

class ColorData {
    virtual ~ColorData() {}

    virtual const void* getRawData() = 0;
    virtual float getValue(int x, int y, int channel) const = 0;
    virtual float setValue(int x, int y, int channel, float value) const = 0;

    float operator() (int x, int y, int channel);
    int getDataSize() { return _dataSize; }

protected:
    ColorData(int width, int height, int numChannels, int dataSize);

    int _width;
    int _height;
    int _numChannels;
    int _dataSize;
};

}

#endif