#ifndef RECSYSTEM_ERHORIZONTALCROSSINGSFEATURE_H
#define RECSYSTEM_ERHORIZONTALCROSSINGSFEATURE_H

#include "ICFeature.h"
#include <deque>

namespace nprs {

class ICHCrossingsFeature : public ICFeature {
public:
    ICHCrossingsFeature(Matrix<ERDescriptor*> const* erMap, Image const* image, int channel);

    void init(const Point &p, const ERDescriptor *reg) override;
    void increment(const Point &p, const ERDescriptor *reg) override;
    void combine(const ICFeature *other, const ERDescriptor *thisReg, const ERDescriptor *otherReg) override;
    float getValue() override;

private:
    std::deque<int> _numCrossings;
    int _ytop;
    int _ybottom;
};

}

#endif // RECSYSTEM_ERHORIZONTALCROSSINGSFEATURE_H
