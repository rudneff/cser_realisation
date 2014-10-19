#include "ICFeature.h"

using namespace nprs;


ICFeatureComputer::ICFeatureComputer(const Matrix<ERDescriptor*> *erMap, const Image *image, int channel)
    : _image(image), _erMap(erMap), _channel(channel) 
{
    
}
