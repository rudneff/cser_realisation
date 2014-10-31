#ifndef COMMON_RECTANGLE_H
#define COMMON_RECTANGLE_H

#include <common/Point.h>
#include <algorithm>
#include <cmath>

namespace nprs {

class Rectangle final {
public:
    static Rectangle fromPoints(float x, float y, float x1, float y1);

public:
    Rectangle();
    Rectangle(float x, float y, float width, float height);
    Rectangle(const Point &p1, const Point &p2);

    float x() const { return _x; }
    float y() const { return _y; }
    float width() const { return _width; }
    float height() const { return _height; }

    float x1() const;
    float y1() const;
    float area() const;

    Point middlePoint() const;

    bool operator < (const Rectangle &other) const;
    bool operator == (const Rectangle &other) const;

private:
    float _x;
    float _y;
    float _width;
    float _height;
};

#include "Rectangle.inl"

inline bool Rectangle::operator< (const Rectangle &other) const {
    return middlePoint() < other.middlePoint();
}

inline bool Rectangle::operator== (const Rectangle &other) const {
    return _x == other._x && _y == other._y && _width == other._width && _height == other._height;
}

}

#endif
