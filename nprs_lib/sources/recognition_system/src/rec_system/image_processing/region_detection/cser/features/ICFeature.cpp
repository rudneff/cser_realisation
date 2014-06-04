#include "ICFeature.h"

using namespace nprs;


ICFeature::ICFeature(Matrix<ERDescriptor*> const* erMap, Image const* image, int channel)
    : _image(image), _erMap(erMap), _channel(channel) 
{
}
