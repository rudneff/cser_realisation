inline Size::Size(int size) 
    : _width(size), _height(size)
{
}

inline Size::Size(int width, int height)
    : _width(width)
{
}

inline int Size::width() {
    return _width;
}

inline int Size::height() {
    return _height;
}
