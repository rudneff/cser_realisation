#include "FuzzyCluster.h"

namespace nprs {

FuzzyCluster::FuzzyCluster(RealVec const &centroid, int dimsCount)
: _centroid(centroid), _needRecomputeCentroid(false), _dimsCount(dimsCount)
{
}

RealVec const& FuzzyCluster::centroid() const {

}

void FuzzyCluster::addPoint(const FuzzyPoint &p) {
    _points.push_back(p);
    _needRecomputeCentroid = true;
}

RealVec FuzzyCluster::computeCentroid() const {
    if (_points.size() == 0) {
        return _centroid;
    }

    RealVec sum(std::vector<float>(_dimsCount, 0.0f));
    double sumWeights = 0.0;

    for (int i = 0; i < _points.size(); i++) {
        sum += _points[i].coords() * Math::sqr(_points[i].weight());
        sumWeights += Math::sqr(_points[i].weight());
    }

    return sum / sumWeights;
}

}
