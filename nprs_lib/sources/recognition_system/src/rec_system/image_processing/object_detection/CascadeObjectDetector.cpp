#include <common/image/Image.h>

#include "OcvHelper.h"
#include "CascadeObjectDetector.h"
#include <opencv2/opencv.hpp>
#include <QuartzCore/QuartzCore.h>

namespace nprs {

CascadeObjectDetector::CascadeObjectDetector(const std::string &fileName)  {
    _cvClassifier = up<cv::CascadeClassifier>(new cv::CascadeClassifier(fileName));
}

std::vector<Rectangle> CascadeObjectDetector::detect(const Image &image, const Rectangle &bounds) {
    cv::Size windowSize = _cvClassifier->getOriginalWindowSize();
    cv::Mat cvImg = OcvHelper::imageToCv(image.cropped((int)bounds.x(), (int)bounds.y(), (int)bounds.width(), (int)bounds.height()).resized(windowSize.width, windowSize.height));
    std::vector<cv::Rect> detectedObjects;
    _cvClassifier->detectMultiScale(cvImg, detectedObjects, 1.1, 0);
    std::vector<Rectangle> result;
    for (cv::Rect r : detectedObjects) {
        result.push_back(OcvHelper::cvRectToRect(r));
    }
    return result;
}

}
