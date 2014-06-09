#ifndef RECSYSTEM_ADABOOST_CLASSIFIER_H
#define RECSYSTEM_ADABOOST_CLASSIFIER_H

#include <rec_system/classification/TrainingSet.h>
#include <opencv2/opencv.hpp>

namespace nprs {

class AdaboostClassifier {
public:
    AdaboostClassifier();

    void load(const std::string &fileName);
    void save(const std::string &fileName);

    void train(const TrainingSet &trainingSet);
    float predict(const std::vector<float> &item);

private:
    cv::Boost _cvBoost;

    // 1st - trainData, 2-nd - responses
    std::pair<cv::Mat, cv::Mat> convertTrainData(const TrainingSet &trainSet);
    cv::Mat convertItem(const std::vector<float> &item);
};

}

#endif // RECSYSTEM_ADABOOST_CLASSIFIER_H
