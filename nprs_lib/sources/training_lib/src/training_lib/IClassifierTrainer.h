#ifndef TRAININGLIB_CLASSIFIERTRAINER_H
#define TRAININGLIB_CLASSIFIERTRAINER_H

namespace nprs {

class Classifier;
class InputSample;

class IClassifierTrainer {
public:
    virtual ~IClassifierTrainer() {}
    
    virtual up<Classifier> train() = 0;
    virtual void pushSample(const InputSample &sample, bool isPositive) = 0;
};

}

#endif // TRAININGLIB_CLASSIFIERTRAINER_H
