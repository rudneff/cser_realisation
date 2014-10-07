#ifndef TRAININGLIB_SYMBOLDETECTORTRAINER_H
#define TRAININGLIB_SYMBOLDETECTORTRAINER_H

#include "Sample.h"
#include <memory>
#include <vector>
#include "IClassifierTrainer.h"

namespace nprs {

class Bitmap;
class Image;
class InputSample;
class Classifier;

class SymbolDetectorTrainer {
public:
    SymbolDetectorTrainer();

    void pushPositiveSample(const InputSample &sample);
    void pushNegativeSample(const InputSample &sample);

    up<Classifier> createNMLightClassifier();

private:
    up<IClassifierTrainer> _nmLightTrainer;
};

}

#endif // TRAININGLIB_SYMBOLDETECTORTRAINER_H
