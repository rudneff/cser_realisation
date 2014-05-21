#ifndef COMMON_MATRIX_H
#define COMMON_MATRIX_H

namespace nprs {

template <typename T>
class Matrix {
public:
    Matrix(int width, int height)
        : _width(width), _height(height)
    {
        _data = new T[width * height];
    }

    ~Matrix() {
        delete[] _data;
    }

    T& operator() (int col, int row) {
        return _data[row * _width + col];
    }

private:
    int _width;
    int _height;
    T *_data;
};

}

#endif // COMMON_MATRIX_H
