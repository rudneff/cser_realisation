#include "Image.h"
#include <iostream>
#include <common/exceptions/CommonExceptions.h>
#include <common/math/Math.h>
#include <opencv2/opencv.hpp>

using namespace nprs;

Image::Image(int width, int height, ColorInfo colorInfo)
: _width(width),
  _height(height),
  _colorInfo(colorInfo),
  _data(width * height * colorInfo.numChannels())
{
}

Image::Image(int width, int height, ColorInfo colorInfo, const void *data)
: _width(width),
  _height(height),
  _colorInfo(colorInfo),
  _data(width * height * colorInfo.numChannels())
{
    std::memcpy(&(_data[0]), data, _width * _height * _colorInfo.numChannels() * sizeof(float));
}

Image::Image(const Image &other) 
    : _width(other._width),
      _height(other._height),
      _colorInfo(other._colorInfo),
      _data(other._data)
{
}

Image::Image(Image && other)
    : _width(other._width),
      _height(other._height),
      _colorInfo(other._colorInfo),
      _data(std::move(other._data))
{
}

Image& Image::operator=(Image&& other) {
    if (this != &other) {
        _width = other._width;
        _height = other._height;
        _colorInfo = other._colorInfo;
        _data = std::move(other._data);
    }

    return *this;
}

Image Image::resized(int newWidth, int newHeight) const {
    Image result(newWidth, newHeight, _colorInfo);

    float xRatio = _width / (float) newWidth;
    float yRatio = _height / (float) newHeight;

    for (int x = 0; x < newWidth; x++) {
        for (int y = 0; y < newHeight; y++) {
            for (int ch = 0; ch < _colorInfo.numChannels(); ch++) {
                float px = Math::floor(x * xRatio);
                float py = Math::floor(y * yRatio);

                result(x, y, ch) = getValue((int) px, (int) py, ch);
            }
        }
    }

    return result;

//    if (_colorInfo.format() != ColorFormat::INTENSITY && _colorInfo.numChannels() != 1)
//        throw NotImplementedException("Image::resized(): function implemented only for 1channel floating point images");
//
//    cv::Mat src_cv(_width, _height, CV_32FC1, const_cast<float*>(_data.data()));
//    cv::Mat dst_cv(_width, _height, CV_32FC1);
//    cv::resize(src_cv, dst_cv, cv::Size(newWidth, newHeight));
//    return Image(newWidth, newHeight, ColorInfo(ColorFormat::INTENSITY, 1));
}

Image Image::cropped(int x0, int y0, int width, int height) const {
    Image res(width, height, _colorInfo);

    if (!isInside(x0, y0) || !isInside(x0 + width - 1, y0 + height - 1)) {
        throw ArgumentException("Image::cropped: rectangle is out of image bounds");
    }
    
    for (int x = x0; x < x0 + width; x++) {
        for (int y = y0; y < y0 + height; y++) {
            for (int c = 0; c < _colorInfo.numChannels(); c++) {
                res(x - x0, y - y0, c) = getValue(x, y, c);
            }
        }
    }

    return res;
}

Image Image::copyChannel(int c) const {
    Image res(width(), height(), ColorInfo(ColorFormat::INTENSITY, 1));
    for (int x = 0; x < width(); x++) {
        for (int y = 0; y < height(); y++) {
            res(x, y, 0) = (*this)(x, y, c);
        }
    }
    return res;
}

void Image::computeRange(float *outMin, float *outMax, int channel) const {
    float min = getValue(0, 0, channel);
    float max = min;
    
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
            min = Math::min(getValue(x, y, channel), min);
            max = Math::max(getValue(x, y, channel), max);
        }
    }
    
    *outMin = min;
    *outMax = max;
}
