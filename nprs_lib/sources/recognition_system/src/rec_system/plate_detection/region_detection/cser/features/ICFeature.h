#ifndef RECSYSTEM_ERFEATURE_H
#define RECSYSTEM_ERFEATURE_H

#include "rec_system/plate_detection/region_detection/cser/ERDescriptor.h"
#include "common/NprsStd.h"
#include "common/image/Image.h"

namespace nprs {

class Point;
class ERDescriptor;

// Incrementally computable feature
class ICFeatureComputer {
public:
    ICFeatureComputer(const Matrix<ERDescriptor*> *erMap, const Image *image, int channel);
    virtual ~ICFeatureComputer() {}

    virtual void init(const Point &p, const ERDescriptor *reg) = 0;
    virtual void increment(const Point &p, const ERDescriptor *reg) = 0;
    virtual void combine(const ICFeatureComputer *other, const ERDescriptor *thisReg, const ERDescriptor *otherReg) = 0;

    virtual float getValue() = 0;

protected:
    const Matrix<ERDescriptor*> * getMap() { return _erMap; }
    const Image * getImage() { return _image; }

private:
    const Matrix<ERDescriptor*> *_erMap;
    const Image *_image;
    int _channel;
};

}

#endif // RECSYSTEM_ERFEATURE_H
