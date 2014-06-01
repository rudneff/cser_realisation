#ifndef RECSYSTEM_ERBOUNDS_FEATURE
#define RECSYSTEM_ERBOUNDS_FEATURE

#include "ICFeature.h"

namespace nprs {

class ICAspectRatioFeature : public ICFeature {
public:
    ICAspectRatioFeature(const Matrix<ERDescriptor*> *erMap, const Image *image, int channel);

    void init(Point const& p, ERDescriptor const* reg) override;
    void increment(Point const& p, ERDescriptor const* reg) override;
    void combine(ICFeature const* other, ERDescriptor const* thisReg, ERDescriptor const* otherReg) override;

    float getValue() override;

private:
    Rectangle _bounds;
};

}

#endif // RECSYSTEM_ERBOUNDS_FEATURE
