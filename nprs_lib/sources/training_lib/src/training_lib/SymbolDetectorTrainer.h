#ifndef TRAININGLIB_SYMBOLDETECTORTRAINER_H
#define TRAININGLIB_SYMBOLDETECTORTRAINER_H

#include <common/image/Image.h>
#include <rec_system/classification/adaboost/AdaBoostClassifier.h>

namespace nprs {

class SymbolDetectorTrainer {
public:
    void pushSymbolImage(const Image &image);
    AdaboostClassifier createNMLightClassifier();

private:

};

}

#endif // TRAININGLIB_SYMBOLDETECTORTRAINER_H