#ifndef RS_ONEVSONETRAINER_H
#define RS_ONEVSONETRAINER_H

#include "Trainer.h"
#include "TrainingSet.h"

namespace nprs {

class OneVsOneTrainer : Trainer {
public:
    OneVsOneTrainer();

    virtual up<DecisionMaker> train(const TrainingSet &dataSet);
};

}

#endif // RS_ONEVSONETRAINER_H
