#ifndef RECSYSTEM_ERNUMHOLESFEATURE_H
#define RECSYSTEM_ERNUMHOLESFEATURE_H

#include "ICFeature.h"

namespace nprs {

class ICNumHolesFeature : public ICFeature {
public:
    ICNumHolesFeature(const Matrix<ERDescriptor*> *erMap, const Image *image, int channel);
    ~ICNumHolesFeature();

    void init(const Point &p, const ERDescriptor *reg) override;
    void increment(const Point &p, const ERDescriptor *reg) override;
    void combine(const ICFeature *other, const ERDescriptor *thisReg, const ERDescriptor *otherReg) override;
    
    float getValue() override;

private:
    float _genus;

    std::tuple<int, int, int> computePatterns(const Matrix<int> &region);
};

}


#endif // RECSYSTEM_ERNUMHOLESFEATURE_H
