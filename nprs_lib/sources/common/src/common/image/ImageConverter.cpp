#include "ImageConverter.h"

void nprs::ImageConverter::bgraByte255ToLumFloat1(Image<float> &result, const Image<uchar> &image) {
    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            result(x, y, 0) = (0, 0.2126 * image(x,y,3) + 0.7152 * image(x,y,2) + 0.0722 * image(x,y,1)) / 255.0f;
        }
    }
}

void nprs::ImageConverter::rgbaByte255ToLumFloat1(Image<float> &result, Image<uchar> const& image) {
    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            result(x, y, 0) = (0, 0.2126 * image(x, y, 0) + 0.7152 * image(x, y, 1) + 0.0722 * image(x, y, 2)) / 255.0f;
        }
    }
}

nprs::Image<uchar> nprs::ImageConverter::bgraByte255ToLumByte255(Image<uchar> const& image) {
    Image<uchar> result(image.width(), image.height(), ColorInfo(COLORFORMAT_I255, 1));
    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            result(x, y, 0) = (0, 0.2126 * image(x, y, 3) + 0.7152 * image(x, y, 2) + 0.0722 * image(x, y, 1));
        }
    }

    return result;
}
