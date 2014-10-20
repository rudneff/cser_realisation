#include "HogFeatureExtractor.h"
//#include <opencv2/opencv.hpp>
#include <rec_system/image_processing/object_detection/OcvHelper.h>
#include <rec_system/image_processing/SimpleGradientOperator.h>
#include <common/functional/ListProcessing.h>
#include <iostream>

namespace nprs {

HogFeatureExtractor::HogFeatureExtractor()
    : _gradientOperator(new SimpleGradientOperator())
{
}

static void debugPrintVector(std::vector<float> const& vec) {
    for (float val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

std::vector<float> HogFeatureExtractor::extract(const Image &image, int channel, const Rectangle &bounds) {
    Image gradients = _gradientOperator->performUnbounded(image.cropped(bounds).resized(20, 20), channel);
    Rectangle xbounds = Rectangle(0, 0, gradients.width(), gradients.height());

    //Image gradients = _gradientOperator->perform(image, channel, bounds);
    //Rectangle xbounds = bounds;

    std::vector<float> result;
    std::vector<Rectangle> areas;
 
    areas.push_back(Rectangle(
        xbounds.x(), xbounds.y(),
        xbounds.width() / 2, xbounds.height() / 2));

    areas.push_back(Rectangle(
        xbounds.x() + xbounds.width() / 2,
        xbounds.y(), xbounds.width() / 2, xbounds.height() / 2));

    areas.push_back(Rectangle(
        xbounds.x(), xbounds.y() + xbounds.height() / 2,
        xbounds.width() / 2, xbounds.height() / 2));

    areas.push_back(Rectangle(
        xbounds.x() + xbounds.width() / 2, xbounds.y() + xbounds.height() / 2,
        xbounds.width() / 2, xbounds.height() / 2));

    Image weightedAngles(gradients.width(), gradients.height(), ColorInfo(ColorFormat::INTENSITY, 1));
    for (int x = 0; x < gradients.width(); x++) {
        for (int y = 0; y < gradients.height(); y++) {
            weightedAngles(x, y, 0) = (gradients(x, y, 2) * gradients(x, y, 3) + 3.15f) / 6.3f;
        }
    }

    for (Rectangle area : areas) {
        std::vector<float> hist = calcHog(weightedAngles, 0, area);
        result.insert(result.end(), hist.begin(), hist.end());
    }

//    std::cout << bounds.x() << "; " << bounds.y() << "; " << bounds.width() << "; " << bounds.height() << std::endl;
//    debugPrintVector(result);

    return result;
}

std::vector<float> HogFeatureExtractor::calcHog(const Image &gradients, int channel, Rectangle bounds) {
    HistogramExtractor histExtractor(16);
    std::vector<float> hist = histExtractor.extract(gradients, channel, bounds);

    float sum = nprs::sum(hist);

    for (float &v: hist) {
        v = v / (sum > 0.00001 ? sum : 1.0f);
    }

//    float min = *std::min_element(hist.begin(), hist.end());
//    float max = *std::max_element(hist.begin(), hist.end());
//    for (float &v: hist) {
//        v = (v - min) / ((max - min) > 0.00001 ? (max - min) : 1.0f);
//    }

    return hist;
}

}
