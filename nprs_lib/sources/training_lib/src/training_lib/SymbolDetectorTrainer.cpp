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

using namespace nprs;

SymbolDetectorTrainer::SymbolDetectorTrainer()
    : _nmLightTrainer(new SvmRegressionTrainer()),
     _lightTrainData(new TrainingSet())
{
}

up<DecisionMaker> SymbolDetectorTrainer::createNMLightClassifier() {
    return _nmLightTrainer->train(*_lightTrainData);
}

void SymbolDetectorTrainer::pushPositiveSample(const InputSample &sample) {
    auto extractedSamples = sample.extractNMLightSamples();
    for (Sample const& es : extractedSamples) {
        _lightTrainData->addItem(TrainDataItem(es.featureVector(), 1.0f));
    }
}

void SymbolDetectorTrainer::pushNegativeSample(const InputSample &sample) {
    auto extractedSamples = sample.extractNMLightSamples();
    for (Sample const& es : extractedSamples) {
        _lightTrainData->addItem(TrainDataItem(es.featureVector(), 0.0f));
    }
}
