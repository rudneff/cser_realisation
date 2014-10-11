#ifndef ML_HAARCASCADEDECISIONMAKER
#define ML_HAARCASCADEDECISIONMAKER

#include <common/NprsStd.h>
#include <opencv2/objdetect/objdetect.hpp>
#include "DecisionMaker.h"

namespace nprs {

class HaarCascadeDecisionMaker : public DecisionMaker {
public:
    HaarCascadeDecisionMaker(const std::string &fileName);

    virtual float operator()(const RealVec &sample) const;
    virtual void serialize(const std::string &fileName) const;

private:
    up<cv::CascadeClassifier> _cascadeClassifier;
};

}

#endif // ML_HAARCASCADEDECISIONMAKER
