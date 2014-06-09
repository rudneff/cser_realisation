#ifndef COMMON_RECTANGLE_H
#define COMMON_RECTANGLE_H

#include <common/Point.h>
#include <algorithm>
#include <math.h>

namespace nprs {

class Rectangle final {
public:
    Rectangle()
        : _x(0), _y(0), _width(0), _height(0)
    {}

    Rectangle(float x, float y, float width, float height)
        : _x(x), _y(y), _width(width), _height(height)
    {}

    Rectangle(const Point &p1, const Point &p2)
    {
        _x = fmin(p1.x(), p2.x());
        _y = fmin(p1.y(), p2.y());
        _width = fabs(p1.x() - p2.x());
        _height = fabs(p1.y() - p2.y());
    }

    static Rectangle fromPoints(float x, float y, float x1, float y1) {
        return Rectangle(fmin(x, x1), fmin(y, y1), fmax(x, x1) - fmin(x, x1), fmax(y, y1) - fmin(y, y1));
    }

    float x() const { return _x; }
    float y() const { return _y; }
    float width() const { return _width; }
    float height() const { return _height; }

    float x1() const { return _x + _width; }
    float y1() const { return _y + _height; }

private:
    float _x;
    float _y;
    float _width;
    float _height;
};

}

#endif
