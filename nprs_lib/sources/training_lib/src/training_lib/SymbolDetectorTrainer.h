#ifndef TRAININGLIB_SYMBOLDETECTORTRAINER_H
#define TRAININGLIB_SYMBOLDETECTORTRAINER_H

#include <memory>

namespace nprs {

class Image;
class AdaboostClassifier; using pAdaboostClassifier = std::shared_ptr<AdaboostClassifier>;

class SymbolDetectorTrainer {
public:
    void pushSymbolImage(const Image &image);
    pAdaboostClassifier createNMLightClassifier();

private:
    

};

}

#endif // TRAININGLIB_SYMBOLDETECTORTRAINER_H
