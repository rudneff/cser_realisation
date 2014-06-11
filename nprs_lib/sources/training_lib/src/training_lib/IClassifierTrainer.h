#ifndef TRAININGLIB_CLASSIFIERTRAINER_H
#define TRAININGLIB_CLASSIFIERTRAINER_H

#include <common/image/Image.h>

namespace nprs {

class Classifier; using pClassifier = std::shared_ptr<Classifier>;

class IClassifierTrainer {
public:
    virtual ~IClassifierTrainer();
    
    virtual pClassifier train() = 0;

    virtual void pushPositiveSample(const Image &image) = 0;
    virtual void pushPositiveSample(const std::vector<float> &features) = 0;

    virtual void pushNegativeSample(const Image &image, bool isSceneImage) = 0;
    virtual void pushNegativeSample(const std::vector<float> &features) = 0;
};

}

#endif // TRAININGLIB_CLASSIFIERTRAINER_H
