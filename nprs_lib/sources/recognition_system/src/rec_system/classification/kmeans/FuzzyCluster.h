#ifndef RECSYSTEM_FUZZYCLUSTER_H
#define RECSYSTEM_FUZZYCLUSTER_H

#include <common/math/Vector.h>

namespace nprs {

class FuzzyCluster {
public:
    FuzzyCluster(const RealVec &centroid);

    std::vector<std::pair<RealVec, double>> const& points() const { return _points; }
    RealVec centroid();
    void addPoint(const RealVec &point, double weight);

private:
    std::vector<std::pair<RealVec, double>> _points;
    RealVec _centroid;
    bool _needRecomputeCentroid;
};

}

#endif // RECSYSTEM_FUZZYCLUSTER_H
