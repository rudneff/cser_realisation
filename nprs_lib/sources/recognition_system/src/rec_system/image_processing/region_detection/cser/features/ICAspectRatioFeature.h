#ifndef RECSYSTEM_ERBOUNDS_FEATURE
#define RECSYSTEM_ERBOUNDS_FEATURE

#include "ICFeature.h"

namespace nprs {

class ICAspectRatioFeature : public ICFeature {
public:
    ICAspectRatioFeature(const Matrix<ERDescriptor*> *erMap, const Image *image, int channel);

    void init(const Point &p, const ERDescriptor *reg) override;
    void increment(const Point &p, const ERDescriptor *reg) override;
    void combine(const ICFeature *other, const ERDescriptor *thisReg, const ERDescriptor *otherReg) override;

    float getValue() override;

private:
    Rectangle _bounds;
};

}

#endif // RECSYSTEM_ERBOUNDS_FEATURE
