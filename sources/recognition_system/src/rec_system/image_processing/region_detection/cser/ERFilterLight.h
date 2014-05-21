#ifndef RECSYSTEM_ERFILTERlIGHT_H
#define RECSYSTEM_ERFILTERlIGHT_H

#include <rec_system/image_processing/region_detection/cser/ERFilter.h>

namespace nprs {

class ERFilterLight : public ERFilter {
public:
    ~ERFilterLight() override;
    bool isRegion(const ExtremalRegion& region) override;
};

}

#endif // RECSYSTEM_ERFILTERlIGHT_H
