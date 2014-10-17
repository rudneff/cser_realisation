#ifndef RS_CLUSTERER_H
#define RS_CLUSTERER_H

#include <vector>
#include <common/math/Vector.h>

namespace nprs {

class Clusterer {
public:
    virtual ~Clusterer() {}

    virtual std::vector<int> divide(
        const std::vector<RealVec> &items,
        std::vector<RealVec> *outCentroids = 0) = 0;
};

}

#endif // RS_CLUSTERER_H
