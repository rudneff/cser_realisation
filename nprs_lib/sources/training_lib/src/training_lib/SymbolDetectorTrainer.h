#ifndef TRAININGLIB_SYMBOLDETECTORTRAINER_H
#define TRAININGLIB_SYMBOLDETECTORTRAINER_H

#include "Sample.h"
#include <memory>
#include <vector>

namespace nprs {

class Bitmap;
class Image;
class InputSample;
class IClassifierTrainer;
class Classifier;

class SymbolDetectorTrainer {
public:
    SymbolDetectorTrainer();

    void pushPositiveSample(const InputSample &sample);
    void pushNegativeSample(const InputSample &sample);

    sp<Classifier> createNMLightClassifier();

private:
    sp<IClassifierTrainer> _nmLightTrainer;
};

}

#endif // TRAININGLIB_SYMBOLDETECTORTRAINER_H
