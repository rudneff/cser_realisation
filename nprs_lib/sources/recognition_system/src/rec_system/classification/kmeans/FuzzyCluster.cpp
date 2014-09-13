#include "FuzzyCluster.h"

namespace nprs {

FuzzyCluster::FuzzyCluster(RealVec const &centroid)
: _centroid(centroid), _needRecomputeCentroid(false)
{

}

RealVec FuzzyCluster::centroid() {
    if (_needRecomputeCentroid) {
        std::pair<RealVec, double> sum =
            nprs::sum(
                map<std::pair<RealVec, double>, std::pair<RealVec, double>> (
                    _points,
                    [] (const std::pair<RealVec, double> &v) -> std::pair<RealVec, double> {
                        double k = Math::pow(v.second, 2);
                        return std::make_pair<RealVec, double>(v.first * k, k);
                    }
                )
            );
    }

    return _centroid;
}

void FuzzyCluster::addPoint(const RealVec &point, double weight) {
    _points.push_back(std::make_pair(point, weight));
}

}