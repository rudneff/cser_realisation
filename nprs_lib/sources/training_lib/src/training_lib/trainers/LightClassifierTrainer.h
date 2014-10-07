#ifndef TRAININGLIB_LIGHTCLASSIFIERTRAINER_H
#define TRAININGLIB_LIGHTCLASSIFIERTRAINER_H

#include <common/NprsStd.h>
#include <memory>
#include <rec_system/classification/TrainingSet.h>
#include <training_lib/IClassifierTrainer.h>

namespace nprs {

class Classifier;
class InputSample;

class LightClassifierTrainer : public IClassifierTrainer {
public:
    LightClassifierTrainer();

    up<Classifier> train() override;
    void pushSample(const InputSample &sample, bool isPositive) override;

private:
    TrainingSet _trainingSet;
};

}

#endif // TRAININGLIB_LIGHTCLASSIFIERTRAINER_H
