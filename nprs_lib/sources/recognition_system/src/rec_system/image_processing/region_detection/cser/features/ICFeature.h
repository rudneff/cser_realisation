#ifndef RECSYSTEM_ERFEATURE_H
#define RECSYSTEM_ERFEATURE_H

#include "rec_system/image_processing/region_detection/cser/ERDescriptor.h"
#include "common/CommonDefinitions.h"
#include "common/image/Image.h"

namespace nprs {

class Point;
class ERDescriptor;

// Incrementally computable feature
class ICFeature {
public:
    ICFeature(const Matrix<ERDescriptor*> *erMap,  const Image<uchar> *image, int channel)
        : _image(image), _erMap(erMap), _channel(channel)
    {}

    virtual ~ICFeature() {}

    virtual void init(const Point &p, const ERDescriptor *reg) = 0;
    virtual void increment(const Point &p, const ERDescriptor *reg) = 0;
    virtual void combine(const ICFeature *other, const ERDescriptor *thisReg, const ERDescriptor *otherReg) = 0;

    virtual float getValue() = 0;

protected:
    const Matrix<ERDescriptor*> * getMap() { return _erMap; }
    const Image<uchar> * getImage() { return _image; }

private:
    const Matrix<ERDescriptor*> *_erMap;
    const Image<uchar> *_image;
    int _channel;
};

}

#endif // RECSYSTEM_ERFEATURE_H
