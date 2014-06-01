#ifndef RECSYSTEM_ERDESCRIPTOR_H
#define RECSYSTEM_ERDESCRIPTOR_H

#include <vector>
#include <common/Rectangle.h>
#include <common/Matrix.h>
#include <memory>

namespace nprs {

class Point;
class ERDescriptor;
class ICFeature;

class ERDescriptor {
public:
    static const int FEATURE_ASPECTRATIO = 0;
    static const int FEATURE_COMPACTNESS = 1;

    ERDescriptor(const Point& p, const std::vector<ICFeature*> &featureComputers);

    ERDescriptor *attachPoint(const Point &p);
    ERDescriptor *combine(const ERDescriptor *other);

    Rectangle const& bounds() const { return _bounds; }
    int getFeature(int f) const  { return _features[f]; }
    
private:
    explicit ERDescriptor(const std::vector<ICFeature*> &featureComputers);
    ERDescriptor(const std::vector<ICFeature*> &featureComputers, Rectangle bounds);

    const std::vector<ICFeature*> _featureComputers;
    std::vector<float> _features;
    Rectangle _bounds;

    ERDescriptor *_parent;
};

}

#endif // RECSYSTEM_ERDESCRIPTOR_H
