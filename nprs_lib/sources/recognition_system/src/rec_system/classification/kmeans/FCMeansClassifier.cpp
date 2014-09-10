#include <rec_system/classification/TrainingSet.h>
#include "FCMeansClassifier.h"

namespace nprs {

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

}