#include "HogFeatureExtractor.h"
#include <dlib/image_keypoint.h>
#include <common/exceptions/CommonExceptions.h>
#include <opencv2/opencv.hpp>
#include <rec_system/image_processing/object_detection/OcvHelper.h>

namespace nprs {

static void debugPrintVector(std::vector<float> const& vec) {
    for (float val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

HogFeatureExtractor::HogFeatureExtractor()
:_sobelOperator(new SobelOperator())
{
}

std::vector<float> HogFeatureExtractor::extract(const Image &image, const Rectangle &bounds) {
    Image gradients = _sobelOperator->apply(image.cropped(bounds));

    std::vector<float> result;
    std::vector<Rectangle> areas = {
        Rectangle(bounds.x(), bounds.y(), bounds.width() / 2, bounds.height() / 2),
        Rectangle(bounds.x() + bounds.width() / 2, bounds.y(), bounds.width() / 2, bounds.height() / 2),
        Rectangle(bounds.x(), bounds.y() + bounds.height() / 2, bounds.width() / 2, bounds.height() / 2),
        Rectangle(bounds.x() + bounds.width() / 2, bounds.y() + bounds.height() / 2, bounds.width() / 2, bounds.height() / 2),
    };

    for (Rectangle area : areas) {
        std::vector<float> hist = calcHog(gradients, area);
        result.insert(result.end(), hist.begin(), hist.end());
    }

    debugPrintVector(result);

    return result;
}

std::vector<float> HogFeatureExtractor::calcHog(const Image &gradients, Rectangle bounds) {
    HistogramExtractor histExtractor(16, 2);
    return histExtractor.extract(gradients, bounds);
}

}
