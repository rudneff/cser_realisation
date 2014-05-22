#ifndef RECSYSTEM_ERFILTERTHRESHOLD_H
#define RECSYSTEM_ERFILTERTHRESHOLD_H

#include "rec_system/image_processing/region_detection/cser/ERFilter.h"
#include <vector>

namespace nprs {

class Condition;

class ERFilterConditional : public ERFilter {
public:
    ERFilterConditional(const std::vector<Condition> &conditions);

    bool isRegion(ERDescriptor const& region) override;

private:
    std::vector<Condition> _conditions;
};

class Condition {

};

}

#endif // RECSYSTEM_ERFILTERTHRESHOLD_H