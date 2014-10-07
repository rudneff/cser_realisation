#ifndef RECSYSTEM_KMEANSCLASSIFIER_H
#define RECSYSTEM_KMEANSCLASSIFIER_H

#include <common/NprsStd.h>
#include <rec_system/classification/Classifier.h>
#include <rec_system/clusterization/Clusterer.h>
#include "FuzzyCluster.h"

namespace nprs {

class FCMeansClusterer : public Clusterer {
public:
    FCMeansClusterer(float m = 2.0f);

    virtual std::vector<int> divide(
        const std::vector<RealVec> &items,
        std::vector<RealVec> *outCentroids = 0) override;

private:
    std::vector<RealVec> _clusterCenters;
    int _numClusters;
    int _numDims;
    float _m;

    std::vector<up<FuzzyCluster>> initializeClusters(int numClusters, const TrainingSet &trainingSet) const;
    RealVec generateRandomCentroid(std::vector<float> const& minRange, std::vector<float> const& maxRange) const;
    std::vector<up<FuzzyCluster>> updateClusters(std::vector<up<FuzzyCluster>> const& clusters) const;
};

}

#endif // RECSYSTEM_KMEANSCLASSIFIER_H
