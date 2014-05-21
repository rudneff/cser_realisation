#include "ImageConverter.h"

std::shared_ptr<nprs::Image<float>> nprs::ImageConverter::bgraByte255ToLumFloat1(const pImage<uchar> &image) {
    pImage<float> result = pImage<float>(new Image<float>(image->width(), image->height(), ColorInfo(COLORFORMAT_GRAY_NORM, 1)));

    for (int x = 0; x < result->width(); x++) {
        for (int y = 0; y < result->height(); y++) {
            float r = result->getValue(x, y, 2);
            float g = result->getValue(x, y, 1);
            float b = result->getValue(x, y, 0);
            result->setValue(x, y, 0, (0, 0.2126 * r + 0.7152 * g + 0.0722 * b) / 255.0f);
        }
    }

    return result;
}

std::shared_ptr<nprs::Image<float>> nprs::ImageConverter::rgbaByte255ToLumFloat1(pImage<uchar> const& image) {
    pImage<float> result = pImage<float>(new Image<float>(image->width(), image->height(), ColorInfo(COLORFORMAT_GRAY_NORM, 1)));

    for (int x = 0; x < result->width(); x++) {
        for (int y = 0; y < result->height(); y++) {
            float r = result->getValue(x, y, 0);
            float g = result->getValue(x, y, 1);
            float b = result->getValue(x, y, 2);
            result->setValue(x, y, 0, (0.2126 * r + 0.7152 * g + 0.0722 * b) / 255.0f);
        }
    }

    return result;
}