#ifndef TRAININGLIB_SYMBOLDETECTORTRAINER_H
#define TRAININGLIB_SYMBOLDETECTORTRAINER_H

#include <common/NprsStd.h>
#include <memory>
#include <vector>
#include "IClassifierTrainer.h"

namespace nprs {

class Bitmap;
class Image;
class InputSample;
class DecisionMaker;
class Trainer;
class TrainingSet;

class SymbolDetectorTrainer {
public:
    SymbolDetectorTrainer();

    void pushPositiveSample(const InputSample &sample);
    void pushNegativeSample(const InputSample &sample);

    up<DecisionMaker> createNMLightClassifier();

private:
    up<Trainer> _nmLightTrainer;
    up<TrainingSet> _lightTrainData;
};

}

#endif // TRAININGLIB_SYMBOLDETECTORTRAINER_H
