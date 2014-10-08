#ifndef ML_DECISIONMAKER_H
#define ML_DECISIONMAKER_H

#include <ostream>
#include <common/math/Vector.h>

namespace nprs {

class DecisionMaker {
public:
    virtual float operator() (const RealVec &sample) const = 0;
    virtual void serialize(const std::string &fileName) const = 0;
};

}

#endif // ML_DECISIONMAKER_H
