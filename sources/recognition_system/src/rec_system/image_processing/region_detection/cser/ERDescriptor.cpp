#include "ERDescriptor.h"
#include <common/Point.h>
#include "features/ICFeature.h"

nprs::ERDescriptor::ERDescriptor(const Point &p, const std::vector<ICFeature*> &featureComputers)
    : _bounds(p.x(), p.y(), 1, 1), _featureComputers(featureComputers), _features(featureComputers.size())
{
    for (int i = 0; i < _featureComputers.size(); i++) {
        auto fc = _featureComputers[i];
        fc->init(p, this);
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

    ERDescriptor* newReg = new ERDescriptor(_featureComputers);
    _parent = newReg;

    return newReg;
}

nprs::ERDescriptor* nprs::ERDescriptor::combine(ERDescriptor const* other) {
    for (auto fc : _featureComputers) {
        fc->combine(fc, this, other);
    }

    ERDescriptor *newReg = new ERDescriptor(_featureComputers);
    _parent = newReg;

    return newReg;
}
