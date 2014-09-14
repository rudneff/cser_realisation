#ifndef RECSYSTEM_KMEANSCLASSIFIER_H
#define RECSYSTEM_KMEANSCLASSIFIER_H

#include <common/NprsStd.h>
#include <rec_system/classification/Classifier.h>
#include "FuzzyCluster.h"

namespace nprs {

class FCMeansClassifier : public Classifier {
public:
    FCMeansClassifier(int numDims, int numClusters);

    virtual void load(const std::string &fileName) override;
    virtual void save(const std::string &fileName) const override;
    virtual void train(const TrainingSet &trainingSet) override;
    virtual float predict(const std::vector<float> &item) const override;

private:
    std::vector<up<FuzzyCluster>> _clusters;

    std::vector<up<FuzzyCluster>> initializeClusters(int numClusters, const TrainingSet &trainingSet);
};

}

#endif // RECSYSTEM_KMEANSCLASSIFIER_H
