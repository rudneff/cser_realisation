#include <common/image/Image.h>
#include "OcvHelper.h"

//namespace nprs {

//cv::Mat nprs::OcvHelper::imageToCv(Image const &image) {
//    cv::Mat result = cv::Mat(image.height(), image.width(), CV_8UC1);
//    for (int x = 0; x < image.width(); x++) {
//        for (int y = 0; y < image.height(); y++) {
//            result.at<unsigned char>(y, x) = (unsigned char)(image(x, y, 0) * 255);
//        }
//    }
//
//    return result;
//}
//
//nprs::Rectangle nprs::OcvHelper::cvRectToRect(const cv::Rect &cvRect) {
//    return nprs::Rectangle(cvRect.x, cvRect.y, cvRect.width, cvRect.height);
//}

//}
