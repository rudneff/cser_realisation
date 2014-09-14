#ifndef RECSYSTEM_FUZZYCLUSTER_H
#define RECSYSTEM_FUZZYCLUSTER_H

#include <common/math/Vector.h>

namespace nprs {

class FuzzyPoint;

class FuzzyCluster {
public:
    FuzzyCluster(const RealVec &centroid, int dimsCount);

    RealVec const& centroid() const;
    std::vector<FuzzyPoint> const& points() const { return _points; }
    void addPoint(const FuzzyPoint &p);

private:
    RealVec _centroid;
    std::vector<FuzzyPoint> _points;
    bool _needRecomputeCentroid;
    int _dimsCount;

    RealVec computeCentroid() const;
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
