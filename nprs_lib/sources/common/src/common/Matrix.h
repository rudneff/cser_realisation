#ifndef COMMON_MATRIX_H
#define COMMON_MATRIX_H

namespace nprs {

template <typename T>
class Matrix {
public:
    Matrix(int width, int height)
        : _width(width), _height(height), _data(width * height)
    {
    }

    ~Matrix() {
    }

    T& operator() (int col, int row) {
        return _data[row * _width + col];
    }

    T const& operator() (int col, int row) const {
        return _data[row * _width + col];
    }

    T const& getValue(int col, int row) const {
        _data[row * _width + col];
    }

    void setValue(int col, int row, const T &value) {
        _data[row * _width + col] = value;
    }

    bool isInBounds(int x, int y) {
        return x >= 0 && x < _width && y >= 0 && y < _height;
    }

private:
    int _width;
    int _height;

    std::vector<T> _data;
};

}

#endif // COMMON_MATRIX_H
