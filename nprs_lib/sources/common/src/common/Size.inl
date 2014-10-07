inline Size::Size(int size) 
    : _width(size), _height(size)
{
}

inline Size::Size(int width, int height)
: _width(width), _height(height)
{
}

inline int Size::width() const {
    return _width;
}

inline int Size::height() const {
    return _height;
}
