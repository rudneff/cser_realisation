#ifndef RECSYSTEM_ADABOOST_CLASSIFIER_H
#define RECSYSTEM_ADABOOST_CLASSIFIER_H

#include <rec_system/classification/TrainingSet.h>
#include <opencv2/opencv.hpp>
#include <rec_system/classification/Classifier.h>

namespace nprs {

class AdaboostClassifier : public Classifier {
public:
    AdaboostClassifier();

    void load(const std::string &fileName) override;
    void save(const std::string &fileName) const override;

    void train(const TrainingSet &trainingSet) override;
    float predict(const std::vector<float> &item) const override;

private:
    cv::Boost _cvBoost;

    // 1st - trainData, 2-nd - responses
    std::pair<cv::Mat, cv::Mat> convertTrainData(const TrainingSet &trainSet) const;
    cv::Mat convertItem(const std::vector<float> &item) const;
};

}

#endif // RECSYSTEM_ADABOOST_CLASSIFIER_H
