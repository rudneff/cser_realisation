#ifndef COMMON_LINE_H
#define COMMON_LINE_H

namespace nprs {

class Line final {
public:
    Line(float x0, float y0, float x1, float y1)
        : _x0(x0), _y0(y0), _x1(x1), _y1(y1)
    {}

    float x0() { return _x0; }
    float y0() { return _y0; }
    float x1() { return _x1; }
    float y1() { return _y1; }

private:
    float _x0;
    float _y0;
    float _x1;
    float _y1;
};

}

#endif // COMMON_LINE_H
