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
    template <typename T> using pvec = std::shared_ptr<std::vector<T>>;

    static const int FEATURE_ASPECTRATIO = 0;
    static const int FEATURE_COMPACTNESS = 1;

    ERDescriptor(const Point& p, const std::vector<ICFeature*> &featureComputers);
    ~ERDescriptor();

    ERDescriptor *attachPoint(const Point &p);
    ERDescriptor *combine(ERDescriptor *other);

    Rectangle const& bounds() const { return _bounds; }
    int getFeature(int f) const  { return _features[f]; }
    std::vector<Point> * points() { return _points; }

private:
    ERDescriptor(const std::vector<ICFeature*> &featureComputers, Rectangle bounds, std::vector<Point> * points);

    const std::vector<ICFeature*> _featureComputers;
    std::vector<Point> *_points;

    std::vector<float> _features;
    Rectangle _bounds;
    ERDescriptor *_parent;
};

}

#endif // RECSYSTEM_ERDESCRIPTOR_H
