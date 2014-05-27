#include "ERFilterConditional.h"
#include "rec_system/image_processing/region_detection/cser/ERDescriptor.h"

nprs::ERFilterConditional::ERFilterConditional(std::function<bool(ERDescriptor const&)>& condition)
    : _condition(condition)
{
}

bool nprs::ERFilterConditional::isRegion(ERDescriptor const& region) {
    return _condition(region);
}
	