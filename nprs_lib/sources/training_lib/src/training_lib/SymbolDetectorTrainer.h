#ifndef TRAININGLIB_SYMBOLDETECTORTRAINER_H
#define TRAININGLIB_SYMBOLDETECTORTRAINER_H

#include <memory>
#include <vector>

namespace nprs {

class Bitmap;
class Image;
class AdaboostClassifier; using pAdaboostClassifier = std::shared_ptr<AdaboostClassifier>;
class IClassifierTrainer; using pIClassifierTrainer = std::shared_ptr<IClassifierTrainer>;
class Classifier; using pClassifier = std::shared_ptr<Classifier>;

class SymbolDetectorTrainer {
public:
    SymbolDetectorTrainer();

    void pushPositiveSample(const Bitmap &image);
    void pushPositiveSample(const Image &image);
    void pushPositiveSample(const std::vector<float> &features);

    void pushNegativeSample(const Bitmap &image, bool isSceneImage, int numSamples);
    void pushNegativeSample(const Image &image, bool isSceneImage);
    void pushNegativeSample(const std::vector<float> &features);

    pClassifier createNMLightClassifier();
    
private:
    pIClassifierTrainer _lightClassifierTrainer;
};

}

#endif // TRAININGLIB_SYMBOLDETECTORTRAINER_H
