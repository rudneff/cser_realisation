#ifndef RECSYSTEM_ERBOUNDS_FEATURE
#define RECSYSTEM_ERBOUNDS_FEATURE
#include <rec_system/image_processing/region_detection/cser/features/ERFeature.h>

namespace nprs {

class ERAspectRatioFeature : public ERFeature {
public:
    explicit ERAspectRatioFeature(Point const& p)
        : ERFeature(p), _bounds(p.x(), p.y(), 1, 1) 
    {}

    ERFeature* attachPoint(Point const& p, Matrix<ERDescriptor*> const& erMap) override;
    ERFeature* merge() override;
    float getValue() override;

private:
    Rectangle _bounds;
};

}

#endif // RECSYSTEM_ERBOUNDS_FEATURE
