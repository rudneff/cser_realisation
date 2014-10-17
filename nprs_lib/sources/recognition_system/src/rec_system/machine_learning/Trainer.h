#ifndef ML_TRAINER_H
#define ML_TRAINER_H

#include <common/NprsStd.h>

namespace nprs {

class DecisionMaker;
class TrainingSet;

class Trainer {
public:
    virtual up<DecisionMaker> train(const TrainingSet &dataSet) = 0;
};

}

#endif // ML_TRAINER_H
