#include "FuzzyCluster.h"

namespace nprs {

FuzzyCluster::FuzzyCluster(RealVec const &centroid)
: _centroid(centroid), _needRecomputeCentroid(false), _dimsCount(centroid.numDims())
{
}

RealVec const& FuzzyCluster::centroid() const {
    throw NotImplementedException("");
}

RealVec FuzzyCluster::computeCentroid(const std::vector<FuzzyPoint> &points) const {
    if (points.size() == 0) {
        return _centroid;
    }

    RealVec sum(std::vector<float>(_dimsCount, 0.0f));
    double sumWeights = 0.0;

    for (int i = 0; i < points.size(); i++) {
        sum += points[i].coords() * Math::sqr(points[i].weight());
        sumWeights += Math::sqr(points[i].weight());
    }

    return sum / sumWeights;
}

float FuzzyCluster::computePointWeight(const RealVec &point) const {
    throw NotImplementedException("");
    
}

}
