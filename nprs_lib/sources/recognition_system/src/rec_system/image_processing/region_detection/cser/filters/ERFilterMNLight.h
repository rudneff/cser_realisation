#ifndef RECSYSTEM_ERFILTERLIGHT_H
#define RECSYSTEM_ERFILTERLIGHT_H

#include <rec_system/image_processing/region_detection/cser/ERFilter.h>

namespace nprs {

class ERFilterMNLight : public ERFilter {
public:
    ~ERFilterMNLight();
    std::vector<ERDescriptor*> perform(const std::vector<ERDescriptor*> &regions) override;
};

}

#endif // RECSYSTEM_ERFILTERLIGHT_H
