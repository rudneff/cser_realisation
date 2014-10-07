#ifndef RECSYSTEM_FUZZYCLUSTER_H
#define RECSYSTEM_FUZZYCLUSTER_H

#include <common/math/Vector.h>

namespace nprs {

class FuzzyPoint;

class FuzzyCluster {
public:
    FuzzyCluster(const RealVec &centroid);

    RealVec const& centroid() const;
    float computePointWeight(const RealVec &point) const;

private:
    RealVec _centroid;
    bool _needRecomputeCentroid;
    int _dimsCount;

    RealVec computeCentroid(std::vector<FuzzyPoint> const& points) const;
};

class FuzzyPoint {
public:
    FuzzyPoint(const RealVec &coords, double weight)
        : _coords(coords), _weight(weight)
    {}

    const RealVec & coords() const { return _coords; };
    double weight() const { return _weight; }

private:
    RealVec _coords;
    double _weight;
};

}

#endif // RECSYSTEM_FUZZYCLUSTER_H
