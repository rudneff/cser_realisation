#ifndef TRAININGLIB_SYMBOLDETECTORTRAINER_H
#define TRAININGLIB_SYMBOLDETECTORTRAINER_H

#include <memory>
#include <vector>
#include <rec_system/classification/TrainingSet.h>

namespace nprs {

class Image;
class AdaboostClassifier; using pAdaboostClassifier = std::shared_ptr<AdaboostClassifier>;

class SymbolDetectorTrainer {
public:
    SymbolDetectorTrainer();

    void pushSymbolImage(const Image &image, int threshold = -1);
    void pushSymbolFeatures(const std::vector<float> &features);

    void pushNonSymbolImage(const Image &image, int threshold = -1);
    void pushNonSymbolsFeatures(const std::vector<float> &features);

    pAdaboostClassifier createNMLightClassifier();
    void trainNMLightClassifier(const std::string &fileName);

private:
    TrainingSet _nmLightTrainingSet;
};

}

#endif // TRAININGLIB_SYMBOLDETECTORTRAINER_H
