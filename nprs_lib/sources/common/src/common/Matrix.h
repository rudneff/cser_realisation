#ifndef COMMON_MATRIX_H
#define COMMON_MATRIX_H

namespace nprs {

template <typename T>
class Matrix final {
public:
    Matrix(int width, int height)
        : _width(width), _height(height), _data(new T[width * height])
    {
    }

    Matrix(const Matrix& other)
        : _width(other._width), _height(other._height), _data(new T[other._width * other._height])
    {
        memcpy(_data, other._data, _width * _height * sizeof(T));
    }

    ~Matrix() {
        delete[] _data;
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

    int width() { return _width; }
    int height() { return _height; }

    bool isInBounds(int x, int y) {
        return x >= 0 && x < _width && y >= 0 && y < _height;
    }

    T* data() {
        return _data;
    }

private:
    int _width;
    int _height;

    T *_data;
};

}

#endif // COMMON_MATRIX_H
