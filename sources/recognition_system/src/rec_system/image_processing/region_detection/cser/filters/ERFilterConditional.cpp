#include "ERFilterConditional.h"
#include "rec_system/image_processing/region_detection/cser/ERDescriptor.h"

nprs::ERFilterConditional::ERFilterConditional(const std::vector<Condition> &conditions)
    : _conditions(conditions)
{
}

bool nprs::ERFilterConditional::isRegion(ERDescriptor const& region) {
    return true;
}