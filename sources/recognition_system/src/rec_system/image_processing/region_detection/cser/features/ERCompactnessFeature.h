#ifndef RECSYSTEM_ERAREAFEATURE_H
#define RECSYSTEM_ERAREAFEATURE_H

#include <rec_system/image_processing/region_detection/cser/features/ERFeature.h>

namespace nprs {

class ERAreaFeature : public ERFeature {
public:
    explicit ERAreaFeature(Point const& p)
        : ERFeature(p) {}

    ERFeature* attachPoint(Point const& p, Matrix<ERDescriptor*> const& erMap) override;
    ERFeature* merge() override;
    float getValue() override;
};

}

#endif // RECSYSTEM_ERAREAFEATURE_H
