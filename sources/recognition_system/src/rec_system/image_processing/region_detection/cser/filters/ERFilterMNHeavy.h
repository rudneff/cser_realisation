#ifndef RECSYSTEM_ERFILTER_HEAVY
#define RECSYSTEM_ERFILTER_HEAVY

#include <rec_system/image_processing/region_detection/cser/ERFilter.h>

namespace nprs {

class ERFilterMNHeavy : public ERFilter {
public:
    bool isRegion(ERDescriptor const& region) override;
};

}

#endif // RECSYSTEM_ERFILTER_HEAVY
