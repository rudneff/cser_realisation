template <typename T>
inline Matrix<T>::Matrix(int width, int height) 
    : _width(width), _height(height), _data(width * height) 
{
}

template <typename T>
inline Matrix<T>::Matrix(T const* data, int width, int height) 
    : _width(width), _height(height), _data(width * height) 
{
    std::copy(data, data + width * height, _data.begin());
}

template <typename T>
inline Matrix<T>::Matrix(Matrix && other) 
    : _width(other._width), _height(other._height), _data(std::move(other._data)) 
{
}

template <typename T>
inline nprs::Matrix<T>& Matrix<T>::operator=(Matrix&& other) {
    if (this != &other) {
        _width = other._width;
        _height = other._height;
        _data = std::move(other._data);
    }
    return *this;
}

template <typename T>
inline T const& Matrix<T>::operator()(int col, int row) const {
    return _data[row * _width + col];
}

template <typename T>
inline T& Matrix<T>::operator()(int col, int row) {
    return _data[row * _width + col];
}

template <typename T>
inline T* Matrix<T>::data() {
    return _data.data();
}

template <typename T>
inline bool Matrix<T>::isInBounds(int x, int y) const {
    return x >= 0 && x < _width && y >= 0 && y < _height;
}

template <typename T>
inline void Matrix<T>::setValue(int col, int row, T const& value) {
    _data[row * _width + col] = value;
}

template <typename T>
inline T const& Matrix<T>::getValue(int col, int row) const {
    return _data[row * _width + col];
}

