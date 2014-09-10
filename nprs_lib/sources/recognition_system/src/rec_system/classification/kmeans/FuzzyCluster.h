#ifndef RECSYSTEM_KMEANSCLUSTER_H
#define RECSYSTEM_KMEANSCLUSTER_H

#include <vector>

namespace nprs {

class FuzzyCluster {
public:


private:
    std::vector<std::pair<std::vector, double>> _points;
    std::vector centroid;
};

}

#endif // RECSYSTEM_KMEANSCLUSTER_H
