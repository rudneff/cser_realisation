#ifndef ML_SVMREGRESSIONDECISIONMAKER_H
#define ML_SVMREGRESSIONDECISIONMAKER_H

#include <common/NprsStd.h>
#include <rec_system/machine_learning/DecisionMaker.h>
#include <rec_system/machine_learning/DLibHelper.h>
#include <dlib/svm/function.h>

namespace nprs {

template <class KernelType>
class DLibDecisionMaker : public DecisionMaker {
public:
    DLibDecisionMaker(dlib::decision_function<KernelType> const& df)
    : _decisionFunction(df)
    {
    }

    float operator() (const RealVec &sample) const override {
        return _decisionFunction(DLibHelper::convertSample(sample));
    }

    void serialize(const std::string &fileName) const override {
        dlib::serialize(fileName) << _decisionFunction;
    }

    static up<DLibDecisionMaker<KernelType>> load(const std::string &fileName) {
        dlib::decision_function<KernelType> df;
        dlib::deserialize(fileName) >> df;

        return up<DLibDecisionMaker<KernelType>>(new DLibDecisionMaker<KernelType>(df));
    }

private:
    dlib::decision_function<KernelType> _decisionFunction;
};

}

#endif // ML_SVMREGRESSIONDECISIONMAKER_H
