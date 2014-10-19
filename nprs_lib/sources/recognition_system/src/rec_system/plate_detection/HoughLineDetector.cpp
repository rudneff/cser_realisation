#include "HoughLineDetector.h"

#include <common/Point.h>
#include <common/Line.h>

namespace nprs {

std::vector<LineDetectorResult> HoughLineDetector::perform() const {

}

LineDetectorResult::LineDetectorResult(const Line &line, const std::vector<Point> &points)
: _line(line), _points(points)
{
}

}
