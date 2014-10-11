#ifndef RS_OCVHELPER_H
#define RS_OCVHELPER_H

#include <opencv2/opencv.hpp>
#include <common/Rectangle.h>

namespace nprs {

class Image;

class OcvHelper {
public:
    static cv::Mat imageToCv(const Image &image);
    static Rectangle cvRectToRect(const cv::Rect &cvRect);
};

}

#endif // RS_OCVHELPER_H
