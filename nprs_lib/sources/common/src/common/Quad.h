#ifndef COMMON_QUAD_H
#define COMMON_QUAD_H

#include "Point.h"

namespace nprs {

class Quad {
public:
    Quad(
        const Point &p1,
        const Point &p2,
        const Point &p3,
        const Point &p4);

    const Point& p1() const { return _p1; }
    const Point& p2() const { return _p2; }
    const Point& p3() const { return _p3; }
    const Point& p4() const { return _p4; }

private:
    Point _p1;
    Point _p2;
    Point _p3;
    Point _p4;
};


// ---------------------------- Inline Definitions --------------------------------------------------------------------

inline Quad::Quad(
    const Point &p1,
    const Point &p2,
    const Point &p3,
    const Point &p4)
: _p1(p1), _p2(p2), _p3(p3), _p4(p4)
{
}

}

#endif // COMMON_QUAD_H
