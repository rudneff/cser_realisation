#ifndef TRAININGLIB_LIGHTCLASSIFIERTRAINER_H
#define TRAININGLIB_LIGHTCLASSIFIERTRAINER_H

#include <memory>
#include <rec_system/classification/TrainingSet.h>
#include <training_lib/IClassifierTrainer.h>
#include <training_lib/SampleExtractor.h>

namespace nprs {

class Classifier; using pClassifer = std::shared_ptr<Classifier>;

class LightClassifierTrainer : public IClassifierTrainer {
public:
    LightClassifierTrainer();

    pClassifer train() override;

    void pushPositiveSample(const Image &image) override;
    void pushPositiveSample(const std::vector<float> &features) override;

    void pushNegativeSample(const Image &image, bool isSceneImage) override;
    void pushNegativeSample(const std::vector<float> &features) override;

private:
    TrainingSet _trainingSet;
    SampleExtractor _sampleExtractor;
};

}

#endif // TRAININGLIB_LIGHTCLASSIFIERTRAINER_H