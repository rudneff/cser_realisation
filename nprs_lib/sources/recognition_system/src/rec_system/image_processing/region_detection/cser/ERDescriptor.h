#ifndef RECSYSTEM_ERDESCRIPTOR_H
#define RECSYSTEM_ERDESCRIPTOR_H

#include <vector>
#include <common/Rectangle.h>
#include <common/Matrix.h>
#include <memory>

namespace nprs {

class Point;
class ERDescriptor;
class ICFeatureComputer;

class ERDescriptor {
public:
    template <typename T> using pvec = std::shared_ptr<std::vector<T>>;

    static const int FEATURE_ASPECTRATIO = 0;
    static const int FEATURE_COMPACTNESS = 1;
    static const int FEATURE_HCROSSINGS = 2;
    static const int FEATURE_NUMHOLES = 3;

    ERDescriptor(const Point& p, std::vector<ICFeatureComputer*> *featureComputers, int threshold);
    ~ERDescriptor();

    ERDescriptor * attachPoint(const Point &p, int threshold);
    ERDescriptor * combine(ERDescriptor *other, int threshold);
    
    Rectangle const& bounds() const { return _bounds; }
    int getFeature(int f) const  { return _features[f]; }
    std::vector<float> const& featureVector() const { return _features; }

    int threshold() const { return _threshold; }

private:
    ERDescriptor(std::vector<ICFeatureComputer*> *featureComputers, Rectangle bounds, int threshold);

    std::vector<ICFeatureComputer*> *_featureComputers;

    std::vector<float> _features;
    Rectangle _bounds;
    ERDescriptor *_parent;
    int _threshold;
};

}

#endif // RECSYSTEM_ERDESCRIPTOR_H
