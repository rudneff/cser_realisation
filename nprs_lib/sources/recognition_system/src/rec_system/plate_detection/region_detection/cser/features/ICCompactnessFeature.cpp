#include "ICCompactnessFeature.h"
#include <algorithm>

using namespace nprs;

ICCompactnessFeature::ICCompactnessFeature(Matrix<ERDescriptor*> const* erMap,  Image const* img,  int channel)
    : ICFeatureComputer(erMap, img, channel),
      _area(0), _perimeter(0)
{
}

void ICCompactnessFeature::init(const Point &p, const ERDescriptor* reg)
{
    _perimeter = 1;
    _area = 1;
}

void ICCompactnessFeature::increment(Point const& p, ERDescriptor const* reg) {
    _area += 1.0f;

    int sum = 0;
    for (Point q : { Point(-1, 0), Point(1, 0), Point(0, 1), Point(0, -1) }) {
        if (q.x() >= 0 && q.x() < getImage()->width() && q.y() >= 0 && q.y() < getImage()->height()) {
            if ((*getImage())(q.x(), q.y(), 0) <= (*getImage())(p.x(), p.y(), 0)) {
                sum++;
            }
        }
    }

    _perimeter += 4 - sum;
}

void ICCompactnessFeature::combine(const ICFeatureComputer *other, const ERDescriptor *thisReg, const ERDescriptor *otherReg) {
    _perimeter += static_cast<const ICCompactnessFeature*>(other)->_perimeter;
    _area += static_cast<const ICCompactnessFeature*>(other)->_area;
}

float ICCompactnessFeature::getValue() {
    return sqrt(_area) / _perimeter;
}
