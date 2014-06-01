#include "ColorData.h"

using namespace nprs;

ColorData::ColorData(int width, int height, int numChannels, int dataSize) 
    : _width(width), _height(height), _numChannels(numChannels), _dataSize(dataSize)
{
}

float ColorData::operator()(int x, int y, int channel) {
    return getValue(x, y, channel);
}
