#ifndef RECSYSTEM_CLASSIFIER_H
#define RECSYSTEM_CLASSIFIER_H

#include <string>
#include <vector>

namespace nprs {

class TrainingSet;

class Classifier {
public:
    virtual ~Classifier() {};

    virtual void load(const std::string &fileName) = 0;
    virtual void save(const std::string &fileName) const = 0;

    virtual void train(const TrainingSet &trainingSet) = 0;
    virtual float predict(const std::vector<float> &item) const = 0;
};

}

#endif // RECSYSTEM_CLASSIFIER_H
