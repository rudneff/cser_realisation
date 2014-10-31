#include "LightClassifierTrainer.h"

#include <rec_system/classification/adaboost/AdaboostClassifier.h>
#include <training_lib/Sample.h>
#include <training_lib/InputSample.h>
#include <training_lib/SampleExtractor.h>
#include <common/exceptions/CommonExceptions.h>

using namespace nprs;

//LightClassifierTrainer::LightClassifierTrainer()
//{
//}
//
//up<Classifier> LightClassifierTrainer::train() {
//    if (_trainingSet.size() == 0) {
//        throw WrongStateException("LightClassifierTrainer::train(): training set is empty");
//    }
//
//    up<Classifier> classifier = up<AdaboostClassifier>(new AdaboostClassifier());
//    classifier->train(_trainingSet);
//    return classifier;
//}
//
//void LightClassifierTrainer::pushSample(const InputSample &sample, bool isPositive) {
//    std::vector<Sample> samples = sample.extractSamples();
//
//    for (Sample sample : samples) {
//        _trainingSet.addItem(TrainDataItem(sample.featureVector(), isPositive ? 1.0f : -1.0f));
//    }
//}
