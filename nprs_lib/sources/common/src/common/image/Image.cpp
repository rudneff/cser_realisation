#include "Image.h"

using namespace nprs;

Image::Image(int width, int height, ColorInfo colorInfo)
    : _width(width), 
      _height(height), 
      _colorInfo(colorInfo),
      _data(width * height * colorInfo.numChannels())
{
}
