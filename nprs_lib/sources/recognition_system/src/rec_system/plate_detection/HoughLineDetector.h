#ifndef RS_HOUGHLINEDETECTOR_H
#define RS_HOUGHLINEDETECTOR_H

#include <vector>
#include <common/Line.h>
#include <common/Point.h>

namespace nprs {

class Point;
class Line;
class Image;
class Rectangle;
template <typename T> class Matrix;

class LineDetectorResult;
class LineDetectorParameters;
class HoughPoint;

typedef Matrix<std::pair<int, std::vector<Point>>> AccumulatorMatrix;


// --------------------------------------------------------------------------------

class LineDetectorParameters {
public:
    LineDetectorParameters(
        double minLength,
        double maxLength,
        int angleResolution,
        int distResolution,
        double angleDeviation,
        double continuityThreshold);

    double minLength() const { return _minLength; }
    double maxLength() const { return _maxLength; }
    int angleResolution() const { return _angleResolution; }
    int distResolution() const { return _distResolution; }
    double angleDeviation() const { return _angleDeviation; }
    double continuityThreshold() const { return _continuityThreshold; }

private:
    double _minLength;
    double _maxLength;
    int _angleResolution;
    int _distResolution;
    double _angleDeviation;
    double _continuityThreshold;
};


// --------------------------------------------------------------------------------

class HoughLineDetector {
public:
    HoughLineDetector(const LineDetectorParameters &params);

    std::vector<LineDetectorResult> perform(const std::vector<Point> &points) const;

private:
    LineDetectorParameters _params;

    AccumulatorMatrix accumulatePoints(const std::vector<Point> &points, const Rectangle &bounds) const;
    Rectangle findBounds(const std::vector<Point> &points) const;
    Point mapToAccumulatorCoords(const HoughPoint &point, double maxDist) const;
    HoughPoint mapFromAccumulatorCoords(const Point &point, double maxDist);
    double distFromAngle(const Point &point, double angle) const;
};


// --------------------------------------------------------------------------------

class LineDetectorResult {
public:
    LineDetectorResult(const Line &line, const std::vector<Point> &points);

    Line line() const { return _line; }
    const std::vector<Point> & points() const { return _points; }

private:
    Line _line;
    std::vector<Point> _points;
};


// --------------------------------------------------------------------------------

class HoughPoint {
public:
    HoughPoint(double angle, double dist)
        : _dist(dist), _angle(angle)
    {}

    double dist() const { return _dist; }
    double angle() const { return _angle; }

private:
    double _dist;
    double _angle;
};

}

#endif // RS_HOUGHLINEDETECTOR_H
