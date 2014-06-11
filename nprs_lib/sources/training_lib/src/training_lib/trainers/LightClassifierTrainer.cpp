#include "LightClassifierTrainer.h"
#include <rec_system/classification/adaboost/AdaboostClassifier.h>
#include <training_lib/Sample.h>

using namespace nprs;

LightClassifierTrainer::LightClassifierTrainer()
{
}

pClassifer LightClassifierTrainer::train() {
    pClassifer classifier = std::make_shared<AdaboostClassifier>();
    classifier->train(_trainingSet);
    return classifier;
}

void LightClassifierTrainer::pushNegativeSample(const std::vector<float> &features) {
    _trainingSet.addItem(TrainDataItem(features, 0.0f));
}

void LightClassifierTrainer::pushNegativeSample(const Image &image, bool isSceneImage) {
    
}

void LightClassifierTrainer::pushPositiveSample(const std::vector<float> &features) {
    _trainingSet.addItem(TrainDataItem(features, 1.0f));
}

void LightClassifierTrainer::pushPositiveSample(const Image &image) {
    std::vector<Sample> sample = _sampleExtractor.extractPositiveSample(image);
    for (Sample s : sample) {
        _trainingSet.addItem(TrainDataItem(s.region().lightFeatures(), 1.0f));
    }
}
