inline float Image::getValue(int x, int y, int c) const { 
    return _data[ind(x, y, c)]; 
}

inline float& Image::operator()(int x, int y, int c) { 
    return _data[ind(x, y, c)]; 
}

inline float Image::operator()(int x, int y, int c) const {
    return _data[ind(x, y, c)]; 
}

inline float Image::setValue(int x, int y, int c, float value) {
    _data[ind(x, y, c)] = value; 
}

inline bool Image::isInside(int x, int y) const {
    return x >= 0 && x < _width && y >= 0 && y < _height;
}

inline Image Image::cropped(const Rectangle &rect) const {
    return cropped(rect.x(), rect.y(), rect.width(), rect.height());
}
