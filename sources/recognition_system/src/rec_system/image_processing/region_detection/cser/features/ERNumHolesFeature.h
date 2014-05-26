#ifndef RECSYSTEM_ERNUMHOLESFEATURE_H
#define RECSYSTEM_ERNUMHOLESFEATURE_H
#include <rec_system/image_processing/region_detection/cser/features/ERFeature.h>

namespace nprs {

class ERNumHolesFeature : public ERFeature {
public:
    explicit ERNumHolesFeature(Point const& p)
        : ERFeature(p) {}

    ERFeature* attachPoint(Point const& p, Matrix<ERDescriptor*> const& erMap) override;
    ERFeature* merge() override;
    float getValue() override;
};

}


#endif // RECSYSTEM_ERNUMHOLESFEATURE_H
