#include "CserAlgorithm.h"

nprs::CserAlgorithm::CserAlgorithm(Image<uchar> const& image, int channel, std::vector<pERFilter> *filters)
     : _image(image), _erMap(image.width(), image.height())
{
}

nprs::CserAlgorithm::~CserAlgorithm() {
    
}

std::vector<std::shared_ptr<nprs::ERDescriptor>> nprs::CserAlgorithm::perform() {
    return {};
}


