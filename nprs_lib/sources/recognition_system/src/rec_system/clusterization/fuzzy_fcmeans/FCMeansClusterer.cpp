#include <rec_system/classification/TrainingSet.h>
#include "FCMeansClusterer.h"
#include <chrono>
#include <random>

namespace nprs {

FCMeansClusterer::FCMeansClusterer(float m)
: _m(m)
{
}

std::vector<int> FCMeansClusterer::divide(
    const std::vector<RealVec> &items,
    std::vector<RealVec> *outCentroids)
{

}

std::vector<up<FuzzyCluster>> FCMeansClusterer::initializeClusters(
    int numClusters,
    const TrainingSet &trainingSet) const
{
    std::vector<up<FuzzyCluster>> result;

    std::vector<float> minRange = trainingSet.rangeMin();
    std::vector<float> maxRange = trainingSet.rangeMax();

    for (int i = 0; i < numClusters; i++) {
        result.push_back(up<FuzzyCluster>(new FuzzyCluster(generateRandomCentroid(minRange, maxRange))));
    }

    return std::move(result);
}

RealVec FCMeansClusterer::generateRandomCentroid(
    std::vector<float> const &minRange,
    std::vector<float> const &maxRange) const
{
    static std::default_random_engine eng(std::chrono::system_clock::now().time_since_epoch().count());

    std::vector<float> centroidCoords(minRange.size(), 0.0f);
    for (int i = 0; i < centroidCoords.size(); i++) {
        std::uniform_real_distribution<float> dist(minRange[i], maxRange[i]);
        centroidCoords[i] = dist(eng);
    }

    return RealVec(centroidCoords);
}

}
