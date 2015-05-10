#include "ImageConverter.h"
#include <common/exceptions/CommonExceptions.h>

using namespace nprs;

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
    uint8_t *data = result.data();

    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            data[0] = image(x, y, 0) * 255;
            data[1] = image(x, y, 0) * 255;
            data[2] = image(x, y, 0) * 255;
            data[3] = 255;
            data += result.colorInfo().numChannels();
        }
    }
    return result;
}

Bitmap ImageConverter::imageToRawRgb(const Image &image) {
    Bitmap result(image.width(), image.height(), ColorInfo(ColorFormat::RGB, 3));
    uint8_t *data = result.data();

    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            data[0] = image(x, y, 0) * 255;
            data[1] = image(x, y, 0) * 255;
            data[2] = image(x, y, 0) * 255;
            data += result.colorInfo().numChannels();
        }
    }
    return result;
}

Bitmap ImageConverter::imageToRawArgb32(const Image &image) {
    Bitmap result(image.width(), image.height(), ColorInfo(ColorFormat::RGB, 3));
    uint8_t *data = result.data();

    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            data[0] = 255;
            data[1] = image(x, y, 0) * 255;
            data[2] = image(x, y, 0) * 255;
            data[3] = image(x, y, 0) * 255;
            data += result.colorInfo().numChannels();
        }
    }
    return result;
}


Image ImageConverter::bgraToInt(const uint8_t *data, int width, int height) {
    const uint8_t *data_as_byte = data;
    Image result(width, height, ColorInfo(ColorFormat::INTENSITY, 1));

    for (int y = 0; y < result.height(); y++) {
        for (int x = 0; x < result.width(); x++) {
            uint8_t r = data[2];
            uint8_t g = data[1];
            uint8_t b = data[0];
            data_as_byte += 4;
            result(x, y, 0) = 0.2126 * r / 255.0 + 0.7152 * g / 255.0 + 0.0722 * b / 255.0;
        }
    }
    return result;
}

Image ImageConverter::rgbToInt(const uint8_t *data, int width, int height) {
    const uint8_t *data_as_byte = data;
    Image result(width, height, ColorInfo(ColorFormat::INTENSITY, 1));

    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            uint8_t r = data[2];
            uint8_t g = data[1];
            uint8_t b = data[0];
            data_as_byte += 3;

            result(x, y, 0) = 0.2126 * r / 255.0 + 0.7152 * g / 255.0 + 0.0722 * b / 255.0;
        }
    }

    return result;
}

Image ImageConverter::rgbaToInt(const uint8_t *data, int width, int height) {
    Image result(width, height, ColorInfo(ColorFormat::INTENSITY, 1));
    const uint8_t *data_as_byte = data;

    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            uint8_t r = data[2];
            uint8_t g = data[1];
            uint8_t b = data[0];
            data_as_byte += 4;

            result(x, y, 0) = 0.2126 * r / 255.0 + 0.7152 * g / 255.0 + 0.0722 * b / 255.0;
        }
    }

    return result;
}

Image ImageConverter::argb32ToInt(uint8_t const* data, int width, int height) {
    const uint8_t *data_as_byte = data;
    Image result(width, height, ColorInfo(ColorFormat::INTENSITY, 1));

    for (int x = 0; x < result.width(); x++) {
        for (int y = 0; y < result.height(); y++) {
            uint8_t r = data[2];
            uint8_t g = data[1];
            uint8_t b = data[0];
            data_as_byte += 4;
            result(x, y, 0) = 0.2126 * r / 255.0 + 0.7152 * g / 255.0 + 0.0722 * b / 255.0;
        }
    }

    return result;
}