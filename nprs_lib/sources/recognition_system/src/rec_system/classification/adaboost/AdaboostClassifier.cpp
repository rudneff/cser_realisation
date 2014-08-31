#include "AdaboostClassifier.h"

#include <iostream>

using namespace nprs;

AdaboostClassifier::AdaboostClassifier()
{
}

void AdaboostClassifier::save(std::string const& fileName) const {
    _cvBoost.save(fileName.c_str());
}

void AdaboostClassifier::load(std::string const& fileName) {
    _cvBoost.load(fileName.c_str());
}

float AdaboostClassifier::predict(const std::vector<float> &item) const {
    return _cvBoost.predict(convertItem(item));
}

void AdaboostClassifier::train(const TrainingSet &trainingSet) {
    CvBoostParams params;
    params.boost_type = cv::Boost::REAL;

    std::pair<cv::Mat, cv::Mat> trainData = convertTrainData(trainingSet);

    _cvBoost.train(
        trainData.first,
        CV_ROW_SAMPLE,
        trainData.second);
//        cv::Mat(), cv::Mat(), cv::Mat(), cv::Mat(), 
//        params, 
//        true);
}

std::pair<cv::Mat, cv::Mat> AdaboostClassifier::convertTrainData(const TrainingSet &trainSet) const {
    cv::Mat trainData(trainSet.size(), trainSet.featuresCount(), CV_32FC1);
    cv::Mat responses(trainSet.size(), 1, CV_32FC1);

    for (int i = 0; i < trainSet.size(); i++) {
        const TrainDataItem  &item = trainSet(i);
        responses.at<float>(i, 0) = item.response();
        const std::vector<float> &data = item.data();
        for (int j = 0; j < data.size(); j++) {
            trainData.at<float>(i, j) = data[j];
        }
    }

    return std::make_pair(trainData, responses);
}

cv::Mat AdaboostClassifier::convertItem(const std::vector<float> &item) const {
    std::cout << "feature vector size: ";
    std::cout << item.size() << std::endl;
    return cv::Mat(1, item.size(), CV_32FC1);
}
