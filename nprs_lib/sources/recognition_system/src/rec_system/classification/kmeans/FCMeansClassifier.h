#ifndef RECSYSTEM_KMEANSCLASSIFIER_H
#define RECSYSTEM_KMEANSCLASSIFIER_H

#include <rec_system/classification/Classifier.h>

namespace nprs {

class FCMeansClassifier : public Classifier {
public:
    virtual void load(const std::string &fileName) override;
    virtual void save(const std::string &fileName) const override;
    virtual void train(const TrainingSet &trainingSet) override;
    virtual float predict(const std::vector<float> &item) const override;
};

}

#endif // RECSYSTEM_KMEANSCLASSIFIER_H
