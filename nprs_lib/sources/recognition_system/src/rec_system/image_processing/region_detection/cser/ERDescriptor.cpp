#include "ERDescriptor.h"
#include <common/Point.h>
#include "features/ICFeature.h"
#include <cmath>

nprs::ERDescriptor::ERDescriptor(const Point &p, const std::vector<ICFeature*> &featureComputers)
    : _bounds(p.x(), p.y(), 1, 1), _featureComputers(featureComputers), _features(featureComputers.size())
{
    for (int i = 0; i < _featureComputers.size(); i++) {
        auto fc = _featureComputers[i];
        fc->init(p, this);
        _features[i] = fc->getValue();
    }
}

nprs::ERDescriptor::ERDescriptor(std::vector<ICFeature*> const& featureComputers, Rectangle bounds) 
    : _featureComputers(featureComputers), _features(featureComputers.size()), _bounds(bounds)
{
    for (int i = 0; i < _featureComputers.size(); i++) {
        auto fc = _featureComputers[i];
        _features[i] = fc->getValue();
    }
}

nprs::ERDescriptor::ERDescriptor(std::vector<ICFeature*> const& featureComputers) 
    : _featureComputers(featureComputers), _features(featureComputers.size())
{
    for (int i = 0; i < _featureComputers.size(); i++) {
        auto fc = _featureComputers[i];
        _features[i] = fc->getValue();
    }
}

nprs::ERDescriptor* nprs::ERDescriptor::attachPoint(const Point &p) {
    for(auto fc : _featureComputers) {
        fc->increment(p, this);
    }



    Rectangle newBounds = Rectangle::fromPoints(fmin(p.x(), _bounds.x()),
                                                fmin(p.y(), _bounds.y()),
                                                fmax(p.x(), _bounds.x1()),
                                                fmax(p.y(), _bounds.y1()));

    ERDescriptor* newReg = new ERDescriptor(_featureComputers, newBounds);
    _parent = newReg;

    return newReg;
}

nprs::ERDescriptor* nprs::ERDescriptor::combine(ERDescriptor const* other) {
    for (auto fc : _featureComputers) {
        fc->combine(fc, this, other);
    }

    Rectangle newBounds = Rectangle::fromPoints(fmin(other->bounds().x(), _bounds.x()),
                                                fmin(other->bounds().y(), _bounds.y()),
                                                fmax(other->bounds().x1(), _bounds.x1()),
                                                fmax(other->bounds().y1(), _bounds.y1()));

    ERDescriptor *newReg = new ERDescriptor(_featureComputers, newBounds);
    _parent = newReg;

    return newReg;
}
