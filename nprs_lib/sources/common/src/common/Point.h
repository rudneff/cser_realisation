#ifndef COMMON_POINT_H
#define COMMON_POINT_H

namespace nprs {

class Point final {
public:
    Point();
    Point(float x, float y);

    float x() const { return _x; }
    float y() const  { return _y; }

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

}

#endif // COMMON_POINT_H
