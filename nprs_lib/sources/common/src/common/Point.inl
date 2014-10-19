inline Point::Point(float x, float y)
    : _x(x), _y(y)
{}

inline Point Point::operator+(const Point &p1) const {
    return Point(_x + p1._x, _y + p1._y);
}

inline bool Point::operator< (const Point &other) const {
    return _y < other._y ? true : (_y == other._y ? _x < other._x : false);
}

inline bool Point::operator==(const Point &other) const {
    return _y == other._y && _x == other._x;
}

inline bool Point::operator> (const Point &other) const {
    return _y > other._y ? true : (_y == other._y ? _x > other._x : false);
}
