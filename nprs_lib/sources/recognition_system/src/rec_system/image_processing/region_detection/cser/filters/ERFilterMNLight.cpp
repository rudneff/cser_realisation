#include "ERFilterMNLight.h"
#include <rec_system/image_processing/region_detection/cser/ERDescriptor.h>

using namespace nprs;

ERFilterMNLight::~ERFilterMNLight() 
{
}

std::vector<ERDescriptor*> ERFilterMNLight::perform(const std::vector<ERDescriptor*> &regions) {
    std::vector<ERDescriptor*> result;
    for(ERDescriptor * reg : regions) {
        Rectangle const& bounds = reg->bounds();
        if (bounds.width() > 5 && bounds.width() < 60 &&
            bounds.height() > 5 && bounds.height() < 60 &&
            reg->getFeature(ERDescriptor::FEATURE_ASPECTRATIO) < 0.7)
            {
                result.push_back(reg);
            }
    }

    return result;
}
