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
    explicit ERFilterConditional(const std::vector<std::function<bool(const ERDescriptor&)>> &conditions);

    bool isRegion(ERDescriptor const& region) override;

private:
    std::vector<std::function<bool (const ERDescriptor&)>> _conditions;
};

}

#endif // RECSYSTEM_ERFILTERTHRESHOLD_H
