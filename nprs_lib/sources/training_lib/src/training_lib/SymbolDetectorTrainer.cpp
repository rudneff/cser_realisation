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
    pushNMLightPositiveSample(sample);
    pushNMHeavyPositiveSample(sample);
}

void SymbolDetectorTrainer::pushNegativeSample(const InputSample &sample) {
    pushNMLightNegativeSample(sample);
    pushNMHeavyNegativeSample(sample);
}

void SymbolDetectorTrainer::pushNMLightPositiveSample(const InputSample &sample) {
    std::vector<Sample> samples = sample.extractNMLightSamples();
    for (Sample const& es: samples) {
        _lightTrainData->addItem(TrainDataItem(es.featureVector(), 1.0f));
    }
}

void SymbolDetectorTrainer::pushNMHeavyPositiveSample(const InputSample &sample) {
    std::vector<Sample> samples = sample.extractNMHeavySamples();
    for (Sample const& es: samples) {
        _heavyTrainData->addItem(TrainDataItem(es.featureVector(), 1.0f));
    }
}

void SymbolDetectorTrainer::pushNMLightNegativeSample(const InputSample &sample) {
    std::vector<Sample> samples = sample.extractNMLightSamples();
    for (Sample const& es: samples) {
        _lightTrainData->addItem(TrainDataItem(es.featureVector(), 0.0f));
    }
}

void SymbolDetectorTrainer::pushNMHeavyNegativeSample(const InputSample &sample) {
    std::vector<Sample> samples = sample.extractNMHeavySamples();
    for (Sample const& es: samples) {
        _heavyTrainData->addItem(TrainDataItem(es.featureVector(), 0.0f));
    }
}

}
