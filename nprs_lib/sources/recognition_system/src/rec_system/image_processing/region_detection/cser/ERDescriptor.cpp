#include "ERDescriptor.h"
#include <common/Point.h>
#include "features/ICFeature.h"
#include <common/math/Math.h>

using namespace nprs;

ERDescriptor::ERDescriptor(const Point &p, std::vector<ICFeatureComputer*> *featureComputers, int threshold)
    : _bounds(p.x(), p.y(), 1, 1), 
      _featureComputers(featureComputers), 
      _features(featureComputers->size()),
      _threshold(threshold),
      _child(nullptr),
      _parent1(nullptr),
      _parent2(nullptr)

{
    for (int i = 0; i < _featureComputers->size(); i++) {
        auto fc = (*_featureComputers)[i];
        fc->init(p, this);
        _features[i] = fc->getValue();
    }
}

ERDescriptor::ERDescriptor(std::vector<ICFeatureComputer*> *featureComputers, Rectangle bounds, int threshold) 
    : _featureComputers(featureComputers), 
      _features(featureComputers->size()), 
      _bounds(bounds),
      _threshold(threshold),
      _child(nullptr),
      _parent1(nullptr),
      _parent2(nullptr)
{
    for (int i = 0; i < _featureComputers->size(); i++) {
        auto fc = (*_featureComputers)[i];
        _features[i] = fc->getValue();
    }
}

ERDescriptor::~ERDescriptor() {
}

ERDescriptor* ERDescriptor::attachPoint(const Point &p, int threshold) {
    for(auto fc : *_featureComputers) {
        fc->increment(p, this);
    }

    Rectangle newBounds = Rectangle::fromPoints(
        Math::min(p.x(), _bounds.x()),
        Math::min(p.y(), _bounds.y()),
        Math::max(p.x() + 1, _bounds.x1()),
        Math::max(p.y() + 1, _bounds.y1()));

    if (threshold == 254 || threshold == 255) {
        int a = 0;
    }

    ERDescriptor* newReg = new ERDescriptor(_featureComputers, newBounds, threshold);
    _child = newReg;
    newReg->_parent1 = this;

    return newReg;
}

ERDescriptor* ERDescriptor::combine(ERDescriptor *other, int threshold) {
    for (int i = 0; i < _featureComputers->size(); i++) {
        _featureComputers->at(i)->combine(other->_featureComputers->at(i), this, other);
    }

    if (threshold == 254 || threshold == 255) {
        int a = 0;
    }

    Rectangle newBounds = Rectangle::fromPoints(
        Math::min(other->bounds().x(), _bounds.x()),
        Math::min(other->bounds().y(), _bounds.y()),
        Math::max(other->bounds().x1(), _bounds.x1()),
        Math::max(other->bounds().y1(), _bounds.y1()));

    ERDescriptor *newReg = new ERDescriptor(_featureComputers, newBounds, threshold);
    _child = newReg;
    other->_child = newReg;

    newReg->_parent1 = this;
    newReg->_parent2 = other;

    return newReg;
}
