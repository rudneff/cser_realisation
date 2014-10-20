#ifndef COMMON_MATRIX_H
#define COMMON_MATRIX_H

#include <vector>
#include <functional>

namespace nprs {

template <typename T>
class Matrix final {
public:
    Matrix(std::vector<std::vector<T>> rows);
    Matrix(int width, int height);
    Matrix(const T *data, int width, int height);
    Matrix(int width, int height, std::function<T (int, int)> filler);

    T& operator() (int col, int row);
    const T & operator() (int col, int row) const;
    const T & getValue(int col, int row) const;
    void setValue(int col, int row, const T &value);

    int width() const { return _width; }
    int height() const { return _height; }
    bool isInBounds(int x, int y) const;
    T* data();

    const std::vector<T> & flat() const { return _data; }

private:
    int _width;
    int _height;

    std::vector<T> _data;
};

#include "Matrix.inl"

}

#endif // COMMON_MATRIX_H
