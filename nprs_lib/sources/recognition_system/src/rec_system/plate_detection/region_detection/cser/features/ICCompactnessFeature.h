#ifndef RECSYSTEM_ERAREAFEATURE_H
#define RECSYSTEM_ERAREAFEATURE_H

#include "ICFeature.h"

namespace nprs {

class ICCompactnessFeature : public ICFeatureComputer {
public:
    ICCompactnessFeature(const Matrix<ERDescriptor*> *erMap, const Image *img, int channel);

    void init(Point const& p, ERDescriptor const* reg) override;
    void increment(Point const& p, ERDescriptor const* reg) override;
    void combine(ICFeatureComputer const* other, ERDescriptor const* thisReg, ERDescriptor const* otherReg) override;

    float getValue() override;

private:
    float _area;
    float _perimeter;
};

} 

#endif // RECSYSTEM_ERAREAFEATURE_H
