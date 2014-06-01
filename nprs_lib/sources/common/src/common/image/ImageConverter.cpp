#include "ImageConverter.h"
#include "common/exceptions/ArgumentException.h"

using namespace nprs;
using uchar = unsigned char;

Image ImageConverter::convertRaw(unsigned char const* data, int width, int height, ColorFormat colorFormat) {
    switch (colorFormat) {
    case ColorFormat::RGB: return rgbToInt(data, width, height);
    case ColorFormat::BGRA: return bgraToInt(data, width, height);
    default:
        throw ArgumentException("Color format not supported");
    }
}

std::vector<uchar> ImageConverter::grayImageToRawBgra(Image const& image) {
    std::vector<uchar> result(image.width() * image.height() * 4);
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            result[(y * image.width() + x) * 4 + 0] = image(x, y, 0) * 255;
            result[(y * image.width() + x) * 4 + 1] = image(x, y, 0) * 255;
            result[(y * image.width() + x) * 4 + 2] = image(x, y, 0) * 255;
        }
    }
    return result;
}

void ImageConverter::imageToRawRgb(Image const& image, uchar* data) {
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            data[(y * image.width() + x) * 3 + 0] = image(x, y, 0) * 255;
            data[(y * image.width() + x) * 3 + 1] = image(x, y, 0) * 255;
            data[(y * image.width() + x) * 3 + 2] = image(x, y, 0) * 255;
        }
    }
}

Image ImageConverter::bgraToInt(const uchar *data, int width, int height) {
    Image result(width, height, ColorInfo(ColorFormat::INT, 1));
    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            int p = (y * width + x) * 4;
            uchar r = data[p + 2];
            uchar g = data[p + 1];
            uchar b = data[p + 0];

            result(x, y, 0) = (0, 0.2126 * r / 255.0 + 0.7152 * g / 255.0 + 0.0722 * b / 255.0);
        }
    }
    return result;
}

Image ImageConverter::rgbToInt(const uchar *data, int width, int height) {
    Image result(width, height, ColorInfo(ColorFormat::INT, 1));

    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            int p = (y * width + x) * 3;
            uchar r = data[p + 0];
            uchar g = data[p + 1];
            uchar b = data[p + 2];

            result(x, y, 0) = (0, 0.2126 * r / 255.0 + 0.7152 * g / 255.0 + 0.0722 * b / 255.0);
        }
    }

    return result;
}