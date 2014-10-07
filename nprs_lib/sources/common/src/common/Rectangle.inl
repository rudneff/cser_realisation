inline Rectangle::Rectangle() 
    : _x(0), _y(0), _width(0), _height(0)
{}

inline Rectangle::Rectangle(float x, float y, float width, float height) 
    : _x(x), _y(y), _width(width), _height(height)
{}

inline Rectangle::Rectangle(const Point &p1, const Point &p2)
{
    _x = fmin(p1.x(), p2.x());
    _y = fmin(p1.y(), p2.y());
    _width = fabs(p1.x() - p2.x());
    _height = fabs(p1.y() - p2.y());
}

inline Rectangle Rectangle::fromPoints(float x, float y, float x1, float y1) {
    return Rectangle(fmin(x, x1), fmin(y, y1), fmax(x, x1) - fmin(x, x1), fmax(y, y1) - fmin(y, y1));
}

inline float Rectangle::x1() const { 
    return _x + _width; 
}

inline float Rectangle::y1() const { 
    return _y + _height;
}

inline float Rectangle::area() const {
    return _width * _height;
}
