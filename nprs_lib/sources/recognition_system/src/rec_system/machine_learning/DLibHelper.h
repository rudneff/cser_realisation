#ifndef ML_DLIBHELPER_H
#define ML_DLIBHELPER_H

#include <vector>
#include <dlib/svm.h>
#include <rec_system/machine_learning/TrainingSet.h>

namespace nprs {

class DLibHelper {
public:
    static std::pair<std::vector<dlib::matrix<double>>, std::vector<double>>
        convertTrainingSet(const TrainingSet &data);

    static dlib::matrix<double> convertSample(const RealVec &item);
};

}

#endif // ML_DLIBHELPER_H
