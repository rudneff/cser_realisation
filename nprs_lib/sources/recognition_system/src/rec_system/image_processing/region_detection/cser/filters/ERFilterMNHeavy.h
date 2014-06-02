#ifndef RECSYSTEM_ERFILTER_HEAVY
#define RECSYSTEM_ERFILTER_HEAVY

#include <rec_system/image_processing/region_detection/cser/ERFilter.h>

namespace nprs {

class ERFilterMNHeavy : public ERFilter {
public:
    std::vector<ERDescriptor*> perform(const std::vector<ERDescriptor*> &regions) override;
};

}

#endif // RECSYSTEM_ERFILTER_HEAVY
