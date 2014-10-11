#ifndef RS_CASCADEOBJECTDETECTOR_H
#define RS_CASCADEOBJECTDETECTOR_H

#include <common/NprsStd.h>
#include <opencv2/opencv.hpp>
#include "ObjectDetector.h"

namespace nprs {

class CascadeObjectDetector : public ObjectDetector {
public:
    CascadeObjectDetector(const std::string &fileName);

    virtual std::vector<Rectangle> detect(const Image &image, const Rectangle &bounds);

private:
    up<cv::CascadeClassifier> _cvClassifier;
};

}

#endif // RS_CASCADEOBJECTDETECTOR_H
