#ifndef COMMON_POINT_H
#define COMMON_POINT_H

#include <common/math/Math.h>

namespace nprs {

class Point final {
public:
    Point();
    Point(float x, float y);

    float x() const { return _x; }
    float y() const  { return _y; }
    
    double distanceTo(const Point &other);

    inline Point operator+ (const Point &p1) const;

    inline bool operator< (const Point &other) const;
    inline bool operator== (const Point &other) const;
    inline bool operator> (const Point &other) const;

private:
    float _x;
    float _y;
};

#include "Point.inl"
 
inline Point::Point()
: _x(0), _y(0)
{
}

inline double Point::distanceTo(const nprs::Point &other) {
    return Math::sqrt(Math::sqr(_x - other._x) + Math::sqr(_y - other._y));
}

}

#endif // COMMON_POINT_H
