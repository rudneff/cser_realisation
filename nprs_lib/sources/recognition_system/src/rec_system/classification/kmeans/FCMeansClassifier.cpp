#include <rec_system/classification/TrainingSet.h>
#include "FCMeansClassifier.h"

namespace nprs {

FCMeansClassifier::FCMeansClassifier(int numDims, int numClusters)
{

}

void FCMeansClassifier::load(const std::string &fileName) {

}

void FCMeansClassifier::save(const std::string &fileName) const {

}

void FCMeansClassifier::train(const TrainingSet &trainingSet) {
    for(TrainDataItem const& item: trainingSet.items()) {

    }
}

float FCMeansClassifier::predict(const std::vector<float> &item) const {
    return 0;
}

std::vector<up<FuzzyCluster>> FCMeansClassifier::initializeClusters(int numClusters, const TrainingSet &trainingSet) {
    for (int i = 0; i < numClusters; i++) {
    }
}

}