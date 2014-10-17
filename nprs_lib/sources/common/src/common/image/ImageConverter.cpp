#include "ImageConverter.h"
#include <common/exceptions/CommonExceptions.h>

using namespace nprs;
using uchar = unsigned char;

Image ImageConverter::convertRaw(const Bitmap &raw) {
    switch (raw.colorInfo().format()) {
    case ColorFormat::RGB: return rgbToInt(raw.data(), raw.width(), raw.height());
    case ColorFormat::BGRA: return bgraToInt(raw.data(), raw.width(), raw.height());
    case ColorFormat::RGBA: return rgbaToInt(raw.data(), raw.width(), raw.height());
    case ColorFormat::ARGB: return argb32ToInt(raw.data(), raw.width(), raw.height());
    default:
        throw ArgumentException("Color format not supported");
    }
}

Bitmap ImageConverter::imageToRawBgra(const Image &image) {
    Bitmap result(image.width(), image.height(), ColorInfo(ColorFormat::BGRA, 4));
    uchar *data = result.data();
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            data[(y * image.width() + x) * 4 + 0] = image(x, y, 0) * 255;
            data[(y * image.width() + x) * 4 + 1] = image(x, y, 0) * 255;
            data[(y * image.width() + x) * 4 + 2] = image(x, y, 0) * 255;
            data[(y * image.width() + x) * 4 + 3] = 255;
        }
    }
    return result;
}

Bitmap ImageConverter::imageToRawRgb(const Image &image) {
    Bitmap result(image.width(), image.height(), ColorInfo(ColorFormat::RGB, 3));
    uchar *data = result.data();
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            data[(y * image.width() + x) * 3 + 0] = image(x, y, 0) * 255;
            data[(y * image.width() + x) * 3 + 1] = image(x, y, 0) * 255;
            data[(y * image.width() + x) * 3 + 2] = image(x, y, 0) * 255;
        }
    }
    return result;
}

Bitmap ImageConverter::imageToRawArgb32(const Image &image) {
    Bitmap result(image.width(), image.height(), ColorInfo(ColorFormat::RGB, 3));
    uchar *data = result.data();
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            data[(y * image.width() + x) * 4 + 0] = 255;
            data[(y * image.width() + x) * 4 + 1] = image(x, y, 0) * 255;
            data[(y * image.width() + x) * 4 + 2] = image(x, y, 0) * 255;
            data[(y * image.width() + x) * 4 + 3] = image(x, y, 0) * 255;
        }
    }
    return result;
}


Image ImageConverter::bgraToInt(const uchar *data, int width, int height) {
    Image result(width, height, ColorInfo(ColorFormat::INTENSITY, 1));
    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            int p = (y * width + x) * 4;
            uchar r = data[p + 2];
            uchar g = data[p + 1];
            uchar b = data[p + 0];

            result(x, y, 0) = 0.333 * r / 255.0 + 0.333 * g / 255.0 + 0.333 * b / 255.0;
        }
    }
    return result;
}

Image ImageConverter::rgbToInt(const uchar *data, int width, int height) {
    Image result(width, height, ColorInfo(ColorFormat::INTENSITY, 1));

    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            int p = (y * width + x) * 3;
            uchar r = data[p + 0];
            uchar g = data[p + 1];
            uchar b = data[p + 2];

            result(x, y, 0) = 0.333 * r / 255.0 + 0.333 * g / 255.0 + 0.333 * b / 255.0;
        }
    }

    return result;
}

Image ImageConverter::rgbaToInt(const uchar *data, int width, int height) {
    Image result(width, height, ColorInfo(ColorFormat::INTENSITY, 1));

    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            int p = (y * width + x) * 4;
            uchar r = data[p + 0];
            uchar g = data[p + 1];
            uchar b = data[p + 2];

            result(x, y, 0) = 0.333 * r / 255.0 + 0.333 * g / 255.0 + 0.333 * b / 255.0;
        }
    }

    return result;
}

Image ImageConverter::argb32ToInt(uchar const* data, int width, int height) {
    Image result(width, height, ColorInfo(ColorFormat::INTENSITY, 1));

    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            int p = (y * width + x) * 4;
            uchar r = data[p + 1];
            uchar g = data[p + 2];
            uchar b = data[p + 3];

            result(x, y, 0) = 0.333 * r / 255.0 + 0.333 * g / 255.0 + 0.333 * b / 255.0;
        }
    }

    return result;
}