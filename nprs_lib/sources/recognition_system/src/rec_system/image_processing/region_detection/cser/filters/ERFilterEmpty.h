#ifndef RECSYSTEM_ERFILTEREMPTY_H
#define RECSYSTEM_ERFILTEREMPTY_H

#include <rec_system/image_processing/region_detection/cser/ERFilter.h>

namespace nprs {

class ERFilterEmpty : public ERFilter {
public:
    std::vector<ERDescriptor*> perform(const std::vector<ERDescriptor*> &regions) override;
};

}

#endif // RECSYSTEM_ERFILTEREMPTY_H
