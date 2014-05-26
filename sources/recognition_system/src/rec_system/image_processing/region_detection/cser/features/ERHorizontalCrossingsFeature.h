#ifndef RECSYSTEM_ERHORIZONTALCROSSINGSFEATURE_
#define RECSYSTEM_ERHORIZONTALCROSSINGSFEATURE_

#include <rec_system/image_processing/region_detection/cser/features/ERFeature.h>

namespace nprs {

class ERHorizontalCrossingsFeature : public ERFeature {
public:
    explicit ERHorizontalCrossingsFeature(Point const& p)
        : ERFeature(p) {}

    ERFeature* attachPoint(Point const& p, Matrix<ERDescriptor*> const& erMap) override;
    ERFeature* merge() override;
    float getValue() override;

private:
    
};

}

#endif // RECSYSTEM_ERHORIZONTALCROSSINGSFEATURE_
