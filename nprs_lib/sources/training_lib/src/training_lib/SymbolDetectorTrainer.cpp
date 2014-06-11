#include "SymbolDetectorTrainer.h"
#include <rec_system/classification/TrainingSet.h>
#include <rec_system/classification/adaboost/AdaboostClassifier.h>
#include "trainers/LightClassifierTrainer.h"
#include <common/image/ImageConverter.h>

using namespace nprs;

SymbolDetectorTrainer::SymbolDetectorTrainer()
    : _lightClassifierTrainer(new LightClassifierTrainer())
{
    
}

pClassifier SymbolDetectorTrainer::createNMLightClassifier() {
    return _lightClassifierTrainer->train();
}

void SymbolDetectorTrainer::pushPositiveSample(const Bitmap &image) {
    _lightClassifierTrainer->pushPositiveSample(ImageConverter::convertRaw(image));
}

void SymbolDetectorTrainer::pushPositiveSample(const Image &image) {
    _lightClassifierTrainer->pushPositiveSample(image);
}

void SymbolDetectorTrainer::pushPositiveSample(const std::vector<float> &features) {
    _lightClassifierTrainer->pushPositiveSample(features);
}

void SymbolDetectorTrainer::pushNegativeSample(const Bitmap &image, bool isSceneImage, int numSamples) {
    _lightClassifierTrainer->pushNegativeSample(ImageConverter::convertRaw(image), isSceneImage);
}

void SymbolDetectorTrainer::pushNegativeSample(const Image &image, bool isSceneImage) {
    _lightClassifierTrainer->pushNegativeSample(image, isSceneImage);
}

void SymbolDetectorTrainer::pushNegativeSample(const std::vector<float> &features) {
    _lightClassifierTrainer->pushNegativeSample(features);
}
