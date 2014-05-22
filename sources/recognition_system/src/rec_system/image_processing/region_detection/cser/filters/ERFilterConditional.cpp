#include "ERFilterConditional.h"
#include "rec_system/image_processing/region_detection/cser/ERDescriptor.h"

nprs::ERFilterConditional::ERFilterConditional(const std::vector<std::function<bool(const ERDescriptor&)>> &conditions)
    : _conditions(conditions)
{
}

bool nprs::ERFilterConditional::isRegion(ERDescriptor const& region) {
    for (auto c : _conditions) {
        if (!c(region))
            return false;
    }
    return true;
}
