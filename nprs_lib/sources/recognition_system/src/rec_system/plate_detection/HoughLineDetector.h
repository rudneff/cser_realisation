#ifndef RS_HOUGHLINEDETECTOR_H
#define RS_HOUGHLINEDETECTOR_H

#include <vector>
#include <common/Line.h>

namespace nprs {

class Point;
class Line;
class LineDetectorResult;

class HoughLineDetector {
public:
    std::vector<LineDetectorResult> perform() const;

private:

};

class LineDetectorResult {
public:
    LineDetectorResult(const Line &line, const std::vector<Point> &points);

    Line line() const { return _line; }
    std::vector<Point> points() const { return _points; }

private:
    Line _line;
    std::vector<Point> _points;
};

}

#endif // RS_HOUGHLINEDETECTOR_H
