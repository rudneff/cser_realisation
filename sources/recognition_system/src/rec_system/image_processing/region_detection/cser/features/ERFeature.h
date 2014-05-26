#ifndef RECSYSTEM_ERFEATURE_H
#define RECSYSTEM_ERFEATURE_H

#include <rec_system/image_processing/region_detection/cser/ERDescriptor.h>
#include "common/CommonDefinitions.h"

namespace nprs {

class Point;
class ERDescriptor;
template <typename T> 

class ERFeature {
public:
    explicit ERFeature(const Point &p) {}
    virtual ~ERFeature() {}

    virtual ERFeature* attachPoint(const Point &p, const Matrix<ERDescriptor*> &erMap) = 0;
    virtual ERFeature* merge() = 0;
    virtual float value() = 0;
};

}

#endif // RECSYSTEM_ERFEATURE_H
