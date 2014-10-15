#include "SymbolDetectorTrainer.h"
#include <rec_system/machine_learning/TrainingSet.h>
#include <rec_system/classification/adaboost/AdaboostClassifier.h>
#include "trainers/LightClassifierTrainer.h"
#include "InputSample.h"
#include <common/image/ImageConverter.h>
#include <rec_system/machine_learning/SvmRegressionTrainer.h>
#include <rec_system/machine_learning/TrainingSet.h>
#include <training_lib/Sample.h>
#include <rec_system/machine_learning/DecisionMaker.h>

namespace nprs {

SymbolDetectorTrainer::SymbolDetectorTrainer()
    : _nmLightTrainer(new SvmRegressionTrainer()),
      _nmHeavyTrainer(new SvmRegressionTrainer()),
      _lightTrainData(new TrainingSet()),
      _heavyTrainData(new TrainingSet())
{
}

up<DecisionMaker> SymbolDetectorTrainer::createNMLightClassifier() {
    return _nmLightTrainer->train(*_lightTrainData);
}

up<DecisionMaker> SymbolDetectorTrainer::createNMHeavyClassifier() {
    return _nmHeavyTrainer->train(*_heavyTrainData);
}

void SymbolDetectorTrainer::pushPositiveSample(const InputSample &sample) {
    std::vector<Sample> extractedSamples = sample.extractNMLightSamples();
    for (Sample es : extractedSamples) {
        _lightTrainData->addItem(TrainDataItem(es.featureVector(), 1.0f));
        _heavyTrainData->addItem(TrainDataItem(es.featureVector(), 1.0f));
    }
}

void SymbolDetectorTrainer::pushNegativeSample(const InputSample &sample) {
    std::vector<Sample> extractedSamples = sample.extractNMHeavySamples();
    for (Sample es : extractedSamples) {
        _lightTrainData->addItem(TrainDataItem(es.featureVector(), 0.0f));
        _heavyTrainData->addItem(TrainDataItem(es.featureVector(), 0.0f));
    }
}

}
