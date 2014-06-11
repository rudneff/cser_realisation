#include "SymbolDetectorTrainer.h"
#include <rec_system/classification/TrainingSet.h>
#include <rec_system/classification/adaboost/AdaboostClassifier.h>

using namespace nprs;


SymbolDetectorTrainer::SymbolDetectorTrainer() 
    : _nmLightTrainingSet(4)
{
}

pAdaboostClassifier SymbolDetectorTrainer::createNMLightClassifier() {
    pAdaboostClassifier aboost = std::make_shared<AdaboostClassifier>();
    aboost->train(_nmLightTrainingSet);
    return aboost;
}

void SymbolDetectorTrainer::pushSymbolImage(const Image &image, int threshold) {
    
}

void SymbolDetectorTrainer::trainNMLightClassifier(const std::string &fileName) {
    AdaboostClassifier aboost;
    aboost.train(_nmLightTrainingSet);
    aboost.save(fileName);
}

void SymbolDetectorTrainer::pushSymbolFeatures(const std::vector<float> &features) {
    _nmLightTrainingSet.addItem(TrainDataItem(features, 1.0f));
}

void SymbolDetectorTrainer::pushNonSymbolsFeatures(const std::vector<float> &features) {
    _nmLightTrainingSet.addItem(TrainDataItem(features, 0.0f));
}

void SymbolDetectorTrainer::pushNonSymbolImage(const Image &image, int threshold) {
    
}
