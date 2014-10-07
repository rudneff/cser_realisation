#ifndef COMMON_MATRIX_H
#define COMMON_MATRIX_H

namespace nprs {

template <typename T>
class Matrix final {
public:
    Matrix(int width, int height);
    Matrix(const T *data, int width, int height);
    Matrix(Matrix && other);
    Matrix & operator= (Matrix && other);

    T& operator() (int col, int row);
    const T & operator() (int col, int row) const;
    const T & getValue(int col, int row) const;
    void setValue(int col, int row, const T &value);

    int width() const { return _width; }
    int height() const { return _height; }
    bool isInBounds(int x, int y) const;
    T* data();

private:
    int _width;
    int _height;

    std::vector<T> _data;
};

#include "Matrix.inl"

}

#endif // COMMON_MATRIX_H
