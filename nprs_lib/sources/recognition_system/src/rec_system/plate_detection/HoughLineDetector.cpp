#include "HoughLineDetector.h"

#include <common/Point.h>
#include <common/image/Image.h>
#include <common/Matrix.h>
#include <common/math/Math.h>
#include <iostream>

namespace nprs {


// ------------------------ HoughLineDetector -------------------------------------------------------------------------

HoughLineDetector::HoughLineDetector(const LineDetectorParameters &params)
: _params(params)
{
}

std::vector<LineDetectorResult> HoughLineDetector::perform(const std::vector<Point> &points) const {
    Rectangle bounds = findBounds(points);
    AccumulatorMatrix accumulator = accumulatePoints(points, bounds);

    //std::vector<LineDetectorResult> result;
    //for (int x = 0; x < accumulator.width(); x++) {
    //    for (int y = 0; y < accumulator.height(); y++) {
    //        if (accumulator(x, y).first > 10) {
    //            std::vector<Point> pts = accumulator(x, y).second;

    //            Point left = *std::min_element(
    //                pts.begin(), pts.end(),
    //                [](const Point &p1, const Point &p2) { return p1.x() < p2.x(); });

    //            Point right = *std::max_element(
    //                pts.begin(), pts.end(),
    //                [](const Point &p1, const Point &p2) { return p1.x() < p2.x(); });

    //            result.push_back(LineDetectorResult(
    //                Line(left.x(), left.y(), right.x(), right.y()), pts));
    //        }
    //    }
    //}

    std::vector<LineDetectorResult> result;
    auto flatAccumulator = accumulator.flat();
    std::sort(
        flatAccumulator.begin(), flatAccumulator.end(),
        [] (std::pair<int, std::vector<Point>> const&e1, std::pair<int, std::vector<Point>> const& e2) { return e1.first > e2.first; });

    for (int i = 0; i < 10 && i < flatAccumulator.size(); i++) {
        std::vector<Point> pts = flatAccumulator[i].second;

        Point left = *std::min_element(
            pts.begin(), pts.end(),
            [](const Point &p1, const Point &p2) { return p1.x() < p2.x(); });

        Point right = *std::max_element(
            pts.begin(), pts.end(),
            [](const Point &p1, const Point &p2) { return p1.x() < p2.x(); });

        result.push_back(LineDetectorResult(
            Line(left.x(), left.y(), right.x(), right.y()), pts));
    }

    return result;
}


AccumulatorMatrix HoughLineDetector::accumulatePoints(
    const std::vector<Point> &points,
    const Rectangle &bounds) const
{
    AccumulatorMatrix accumulator(
        _params.angleResolution(),
        _params.distResolution(),   
        [] (int x, int y) { return std::make_pair(0, std::vector<Point>()); });

    double maxDist = 1.5 * Math::sqrt(Math::sqr(bounds.x1()) + Math::sqr(bounds.y1()));
    for (Point p: points) {
        for (double angle = 0; angle < Math::PI; angle += Math::PI / (double) _params.angleResolution()) {
            double dist = distFromAngle(p, angle);
            Point accCoords = mapToAccumulatorCoords(HoughPoint(angle, dist), maxDist);
            if (accumulator.isInBounds(accCoords.x(), accCoords.y())) {
                accumulator((int) accCoords.x(), (int) accCoords.y()).first += 1;
                accumulator((int) accCoords.x(), (int) accCoords.y()).second.push_back(p);
            }
            else {
                std::cout << "WARNING: point [" << accCoords.x() << ", " << accCoords.y() << "] was outside of bounds of accumulator matrix" << std::endl;
            }
        }
    }

    return accumulator;
}

Rectangle HoughLineDetector::findBounds(const std::vector<Point> &points) const {
    Point rightTop = *std::min_element(points.begin(), points.end());
    Point leftBottom = *std::max_element(points.begin(), points.end());

    return Rectangle(rightTop.x(), rightTop.y(), leftBottom.x(), leftBottom.y());
}

Point HoughLineDetector::mapToAccumulatorCoords(const HoughPoint &point, double maxDist) const {
    double angle = Math::rescaleValue(
        point.angle(),
        0, _params.angleResolution(),
        0, Math::PI);

    double dist = Math::rescaleValue(
        point.dist(),
        0, _params.distResolution(),
        0, maxDist);

    return Point((int) Math::floor(angle), (int) Math::floor(dist));
}

HoughPoint HoughLineDetector::mapFromAccumulatorCoords(const Point &point, double maxDist) {
    double angle = Math::rescaleValue(
        point.x(),
        0, Math::PI,
        0, _params.angleResolution());

    double dist = Math::rescaleValue(
        point.y(),
        0, maxDist,
        0, _params.distResolution());

    return HoughPoint(angle, dist);
}

double HoughLineDetector::distFromAngle(const Point &point, double angle) const {
    return Math::abs(point.x() * Math::cos(angle) + point.y() * Math::sin(angle));
}


// ------------------------ LineDetectorResult ------------------------------------------------------------------------

LineDetectorResult::LineDetectorResult(const Line &line, const std::vector<Point> &points)
    : _line(line), _points(points)
{
}


// ------------------------ LineDetectorParameters --------------------------------------------------------------------

LineDetectorParameters::LineDetectorParameters(
    double minLength,
    double maxLength,
    int angleResolution,
    int distResolution,
    double angleDeviation,
    double continuityThreshold)
    : _minLength(minLength),
      _maxLength(maxLength),
      _angleResolution(angleResolution),
      _distResolution(distResolution),
      _angleDeviation(angleDeviation),
      _continuityThreshold(continuityThreshold)
{
}

}
