#ifndef RECSYSTEM_ERFILTER_HEAVY
#define RECSYSTEM_ERFILTER_HEAVY

#include <rec_system/image_processing/region_detection/cser/ERFilter.h>

namespace nprs {

class ERFilterHeavy : public ERFilter {
public:
    bool isRegion(ExtremalRegion const& region) override;
};

}

#endif // RECSYSTEM_ERFILTER_HEAVY
