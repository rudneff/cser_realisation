#ifndef COMMON_RECTANGLE_H
#define COMMON_RECTANGLE_H

#include <common/Point.h>
#include <math.h>

namespace nprs {

class Rectangle {
public:
    Rectangle(float x, float y, float width, float height)
        : _x(x), _y(y), _width(width), _height(height)
    {}

    Rectangle(Point const& p1, Point const& p2)
    {
        _x = fmin(p1.x(), p2.x());
        _y = fmin(p1.y(), p2.y());
        _width = fabs(p1.x() - p2.x());
        _height = fabs(p1.y() - p2.y());
    }

    float x() const { return _x; }
    float y() const { return _y; }
    float width() const { return _width; }
    float height() const { return _height; }

    float x1() { return _x + _width; }
    float y1() { return _y + _height; }

private:
    float _x;
    float _y;
    float _width;
    float _height;
};

}

#endif
