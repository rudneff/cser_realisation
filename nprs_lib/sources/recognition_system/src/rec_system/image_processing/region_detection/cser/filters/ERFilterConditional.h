#ifndef RECSYSTEM_ERFILTERTHRESHOLD_H
#define RECSYSTEM_ERFILTERTHRESHOLD_H

#include "rec_system/image_processing/region_detection/cser/ERFilter.h"
#include <vector>
#include <memory>
#include <functional>

namespace nprs {

class ERDescriptor;

class ERFilterConditional : public ERFilter {
public:
    ERFilterConditional(std::function<bool(const ERDescriptor&)> &condition);

    bool isRegion(ERDescriptor const& region) override;

private:
    std::function<bool (const ERDescriptor&)> _condition;
};

}

#endif // RECSYSTEM_ERFILTERTHRESHOLD_H
