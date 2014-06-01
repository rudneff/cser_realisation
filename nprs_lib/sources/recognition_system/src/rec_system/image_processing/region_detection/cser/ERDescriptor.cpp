#include "ERDescriptor.h"
#include <common/Point.h>
#include "features/ICFeature.h"
#include <cmath>

using namespace nprs;

ERDescriptor::ERDescriptor(const Point &p, const std::vector<ICFeature*> &featureComputers)
    : _bounds(p.x(), p.y(), 1, 1), _featureComputers(featureComputers), _features(featureComputers.size()), _points(new std::vector<Point>())
{
    for (int i = 0; i < _featureComputers.size(); i++) {
        auto fc = _featureComputers[i];
        fc->init(p, this);
        _features[i] = fc->getValue();
    }

    _points->push_back(p);
}

ERDescriptor::~ERDescriptor() {
    
}

ERDescriptor::ERDescriptor(std::vector<ICFeature*> const& featureComputers, Rectangle bounds, std::vector<Point> *points) 
    : _featureComputers(featureComputers), _features(featureComputers.size()), _bounds(bounds), _points(points)
{
    for (int i = 0; i < _featureComputers.size(); i++) {
        auto fc = _featureComputers[i];
        _features[i] = fc->getValue();
    }
}

ERDescriptor* ERDescriptor::attachPoint(const Point &p) {
    for(auto fc : _featureComputers) {
        fc->increment(p, this);
    }



    Rectangle newBounds = Rectangle::fromPoints(fmin(p.x(), _bounds.x()),
                                                fmin(p.y(), _bounds.y()),
                                                fmax(p.x() + 1, _bounds.x1()),
                                                fmax(p.y() + 1, _bounds.y1()));

    _points->push_back(p);
    ERDescriptor* newReg = new ERDescriptor(_featureComputers, newBounds, _points);
    _parent = newReg;

    return newReg;
}

ERDescriptor* ERDescriptor::combine(ERDescriptor *other) {
    for (auto fc : _featureComputers) {
        fc->combine(fc, this, other);
    }

    Rectangle newBounds = Rectangle::fromPoints(fmin(other->bounds().x(), _bounds.x()),
                                                fmin(other->bounds().y(), _bounds.y()),
                                                fmax(other->bounds().x1(), _bounds.x1()),
                                                fmax(other->bounds().y1(), _bounds.y1()));

    _points->insert(_points->end(), other->_points->begin(), other->_points->end());
    delete other->_points;
    other->_points = 0;

    ERDescriptor *newReg = new ERDescriptor(_featureComputers, newBounds, _points);
    _parent = newReg;

    return newReg;
}
