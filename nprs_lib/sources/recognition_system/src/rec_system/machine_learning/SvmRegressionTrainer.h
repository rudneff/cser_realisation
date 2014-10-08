#ifndef ML_SVMREGRESSIONTRAINER_H
#define ML_SVMREGRESSIONTRAINER_H

#include "Trainer.h"

namespace nprs {

class SvmRegressionTrainer : public Trainer {
public:
    virtual up<DecisionMaker> train(const TrainingSet &dataSet) override;
};

}

#endif // ML_SVMREGRESSIONTRAINER_H
