#include "ICAspectRatioFeature.h"
#include <algorithm>

using namespace nprs;
using namespace std;

ICAspectRatioFeature::ICAspectRatioFeature(Matrix<ERDescriptor*> const* erMap, Image const* image, int channel) 
    : ICFeature(erMap, image, channel)
{}

void ICAspectRatioFeature::init(Point const& p, ERDescriptor const* reg) {
    _bounds = Rectangle(p.x(), p.y(), 1, 1);
}

void ICAspectRatioFeature::increment(Point const& p, ERDescriptor const* reg) {
    float x = fmin(p.x(), _bounds.x());
    float y = fmin(p.y(), _bounds.y());
    float x1 = fmax(p.x(), _bounds.x1());
    float y1 = fmax(p.y(), _bounds.y1());

    _bounds = Rectangle::fromPoints(x, y, x1, y1);
}

void ICAspectRatioFeature::combine(ICFeature const* other, ERDescriptor const* thisReg, ERDescriptor const* otherReg) {
    const ICAspectRatioFeature *o = static_cast<const ICAspectRatioFeature*>(other);

    float x = fmin(o->_bounds.x(), _bounds.x());
    float y = fmin(o->_bounds.y(), _bounds.y());
    float x1 = fmax(o->_bounds.x1(), _bounds.x1());
    float y1 = fmax(o->_bounds.y1(), _bounds.y1());

    _bounds = Rectangle::fromPoints(x, y, x1, y1);
}

float ICAspectRatioFeature::getValue() {
    return _bounds.height() != 0 ? _bounds.width() / _bounds.height() : 0.0f;
}
