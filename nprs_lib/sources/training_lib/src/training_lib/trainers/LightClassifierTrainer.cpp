#include "LightClassifierTrainer.h"

#include <rec_system/classification/adaboost/AdaboostClassifier.h>
#include <training_lib/Sample.h>
#include <training_lib/InputSample.h>
#include <training_lib/SampleExtractor.h>

using namespace nprs;

LightClassifierTrainer::LightClassifierTrainer()
{
}

sp<Classifier> LightClassifierTrainer::train() {
    sp<Classifier> classifier = make_shared<AdaboostClassifier>();
    classifier->train(_trainingSet);
    return classifier;
}

void LightClassifierTrainer::pushSample(const InputSample &sample, bool isPositive) {
    sp<SampleExtractor> extractor = sample.createExtractor();
    std::vector<Sample> samples = extractor->extractNMLightSamples();
    for (Sample sample : samples) {
        _trainingSet.addItem(TrainDataItem(sample.featureVector(), isPositive ? 1.0f : 0.0f));
    }
}
