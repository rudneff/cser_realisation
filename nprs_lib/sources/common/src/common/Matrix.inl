template <typename T>
inline Matrix<T>::Matrix(std::vector<std::vector<T>> rows) 
: _width(rows.size()),
  _height(rows.begin()->size()),
  _data(_width * _height)
{
    for (int row = 0; row < rows.size(); row++) {
        for (int col = 0; col < rows[row].size(); col++) {
            _data[row * _width + col] = rows[row][col];
        }
    }
}

template <typename T>
inline Matrix<T>::Matrix(int width, int height) 
    : _width(width), _height(height), _data(width * height) 
{
}

template <typename T>
inline Matrix<T>::Matrix(const T *data, int width, int height) 
    : _width(width), _height(height), _data(width * height) 
{
    std::copy(data, data + width * height, _data.begin());
}

template <typename T>
inline Matrix<T>::Matrix(int width, int height, std::function<T (int, int)> filler)
: _width(width), _height(height), _data(width * height)
{
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            setValue(x, y, filler(x, y));
        }
    }
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
inline void Matrix<T>::setValue(int col, int row, const T &value) {
    _data[row * _width + col] = value;
}

template <typename T>
inline const T& Matrix<T>::getValue(int col, int row) const {
    return _data[row * _width + col];
}
