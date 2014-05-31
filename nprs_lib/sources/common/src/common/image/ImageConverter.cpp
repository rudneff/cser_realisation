#include "ImageConverter.h"

using namespace nprs;

nprs::Image<uchar> nprs::ImageConverter::toLum255(Image<uchar> const& image) {
    if (image.getColorInfo().format() == ColorFormat::RGB255) {
        return rgbToLum255(image);
    }
    else if (image.getColorInfo().format() == ColorFormat::BGRA255) {
        return bgraToLum255(image);
    }
}

Image<uchar> ImageConverter::toInt255(Image<uchar> const& image) {
    Image<uchar> result(image.width(), image.height(), ColorInfo(ColorFormat::I255, 1,1));
    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            int sum = 0;
            for (int c = 0; c < result.getColorInfo().numChannels(); c++) {
                sum += image(x,y,c);
            }
            result(x, y, 0) = sum / (double) image.getColorInfo().numChannels();
        }
    }
    return result;
}

nprs::Image<unsigned char> nprs::ImageConverter::bgraToLum255(Image<uchar> const& image) {
    Image<uchar> result(image.width(), image.height(), ColorInfo(ColorFormat::I255, 1, 1));
    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            result(x, y, 0) = (0, 0.2126 * image(x, y, 3) + 0.7152 * image(x, y, 2) + 0.0722 * image(x, y, 1));
        }
    }
    return result;
}

nprs::Image<unsigned char> nprs::ImageConverter::rgbToLum255(Image<uchar> const& image) {
    Image<uchar> result(image.width(), image.height(), ColorInfo(ColorFormat::I255, 1, 1));
    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            result(x, y, 0) = (0, 0.2126 * image(x, y, 0) + 0.7152 * image(x, y, 1) + 0.0722 * image(x, y, 2));
        }
    }
    return result;
}