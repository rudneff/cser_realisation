#ifndef COMMON_POINT_H
#define COMMON_POINT_H

namespace nprs {

class Point {
public:
    Point(float x, float y) 
        : _x(x), _y(y)
    {}

    float x() const { return _x; }
    float y() const  { return _y; }

private:
    float _x;
    float _y;
};

}

#endif // COMMON_POINT_H
