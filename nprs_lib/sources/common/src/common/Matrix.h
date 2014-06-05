#ifndef COMMON_MATRIX_H
#define COMMON_MATRIX_H

namespace nprs {

template <typename T>
class Matrix final {
public:
    Matrix(int width, int height)
        : _width(width), _height(height), _data(width * height)
    {
    }

    Matrix(const T *data, int width, int height) 
        : _width(width), _height(height), _data(width * height)
    {
        std::copy(data, data + width * height, _data.begin());
    }

    Matrix(Matrix && other) 
        : _width(other._width), _height(other._height), _data(std::move(other._data))
    {
    }

    Matrix& operator= (Matrix && other) {
        if (this != &other) {
            _width = other._width;
            _height = other._height;
            _data = std::move(other._data);
        }

        return *this;
    }

    T& operator() (int col, int row) {
        return _data[row * _width + col];
    }

    const T& operator() (int col, int row) const {
        return _data[row * _width + col];
    }

    T const& getValue(int col, int row) const {
        return _data[row * _width + col];
    }

    void setValue(int col, int row, const T &value) {
        _data[row * _width + col] = value;
    }

    int width() const { return _width; }
    int height() const { return _height; }

    bool isInBounds(int x, int y) const {
        return x >= 0 && x < _width && y >= 0 && y < _height;
    }

    T* data() {
        return _data.data();
    }

private:
    int _width;
    int _height;

    std::vector<T> _data;
};

}

#endif // COMMON_MATRIX_H
