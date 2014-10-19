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
    friend class CserAlgorithm;

    static const int FEATURE_ASPECTRATIO = 0;
    static const int FEATURE_COMPACTNESS = 1;
    static const int FEATURE_HCROSSINGS = 2;
    static const int FEATURE_NUMHOLES = 3;

    ERDescriptor(const Point& p, std::vector<ICFeatureComputer*> *featureComputers, int threshold);
    ~ERDescriptor();

    ERDescriptor * attachPoint(const Point &p, int threshold);
    ERDescriptor * combine(ERDescriptor *other, int threshold);
    
    Rectangle const& bounds() const { return _bounds; }
    float getFeature(int f) const  { return _features[f]; }
    std::vector<float> const& featureVector() const { return _features; }

    int threshold() const { return _threshold; }

    const ERDescriptor * child() const { return _child; }
    const ERDescriptor * parent1() const { return _parent1; }
    const ERDescriptor * parent2() const { return _parent2; }

private:
    ERDescriptor(std::vector<ICFeatureComputer*> *featureComputers, Rectangle bounds, int threshold);

    std::vector<ICFeatureComputer*> *_featureComputers;

    std::vector<float> _features;
    Rectangle _bounds;
    int _threshold;

    ERDescriptor *_child;

    ERDescriptor *_parent1;
    ERDescriptor *_parent2;
};

}

#endif // RECSYSTEM_ERDESCRIPTOR_H
