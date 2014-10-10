#ifndef RECSYSTEM_ERFILTERLIGHT_H
#define RECSYSTEM_ERFILTERLIGHT_H

#include <common/NprsStd.h>
#include <rec_system/machine_learning/DecisionMaker.h>
#include <rec_system/image_processing/region_detection/cser/ERFilter.h>

namespace nprs {

class ERFilterMNLight : public ERFilter {
public:
    static const double THRESHOLD;

    ERFilterMNLight(sp<DecisionMaker> const& regressor);

    ~ERFilterMNLight();
    std::vector<ERDescriptor*> perform(const std::vector<ERDescriptor*> &regions) override;

private:
    sp<DecisionMaker> _regressor;
};

}

#endif // RECSYSTEM_ERFILTERLIGHT_H
