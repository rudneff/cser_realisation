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

    void pushNMLightPositiveSample(const InputSample &sample);
    void pushNMHeavyPositiveSample(const InputSample &sample);
    void pushNMLightNegativeSample(const InputSample &sample);
    void pushNMHeavyNegativeSample(const InputSample &sample);

    up<DecisionMaker> createNMLightClassifier();
    up<DecisionMaker> createNMHeavyClassifier();

private:
    up<Trainer> _nmLightTrainer;
    up<Trainer> _nmHeavyTrainer;
    up<TrainingSet> _lightTrainData;
    up<TrainingSet> _heavyTrainData;
};

}

#endif // TRAININGLIB_SYMBOLDETECTORTRAINER_H
