inline Point::Point(float x, float y)
    : _x(x), _y(y)
{}

inline Point Point::operator+(const Point &p1) const {
    return Point(_x + p1._x, _y + p1._y);
}
