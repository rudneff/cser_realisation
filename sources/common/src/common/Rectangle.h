#ifndef COMMON_RECTANGLE_H
#define COMMON_RECTANGLE_H

namespace nprs {

class Rectangle {
public:
    Rectangle(float x, float y, float width, float height)
        : _x(x), _y(y), _width(width), _height(height)
    {}

    float x() const { return _x; }
    float y() const { return _y; }
    float width() const { return _width; }
    float height() const { return _height; }

private:
    float _x;
    float _y;
    float _width;
    float _height;
};

}

#endif
