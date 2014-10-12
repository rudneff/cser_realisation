#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <common/Matrix.h>

namespace nprs {

class Image;
class Rectangle;

Image convolveImage(const Image &src, const Matrix<float> &mask);

}

#endif // CONVOLUTION_H
