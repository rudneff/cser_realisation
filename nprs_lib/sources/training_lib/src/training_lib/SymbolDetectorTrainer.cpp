#include "SymbolDetectorTrainer.h"
#include <rec_system/classification/TrainingSet.h>
#include <rec_system/classification/adaboost/AdaboostClassifier.h>
#include "trainers/LightClassifierTrainer.h"
#include <common/image/ImageConverter.h>

using namespace nprs;

SymbolDetectorTrainer::SymbolDetectorTrainer()
    : _nmLightTrainer(new LightClassifierTrainer())
{
}

sp<Classifier> SymbolDetectorTrainer::createNMLightClassifier() {
    return _nmLightTrainer->train();
}

void SymbolDetectorTrainer::pushPositiveSample(const InputSample &sample) {
    _nmLightTrainer->pushSample(sample, true);
}

void SymbolDetectorTrainer::pushNegativeSample(const InputSample &sample) {
    _nmLightTrainer->pushSample(sample, false);
}
