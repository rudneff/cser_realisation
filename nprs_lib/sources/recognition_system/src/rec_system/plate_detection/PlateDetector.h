#ifndef RS_PLATEDETECTOR_H
#define RS_PLATEDETECTOR_H

#include <vector>
#include <common/NprsStd.h>
#include <common/Quad.h>
#include <common/Rectangle.h>
#include <functional>

namespace nprs {

class Rectangle;
class ExtremalRegion;
class NumberPlate;
class Quad;

class PlateDetectorParams {
public:
    PlateDetectorParams(int minSymbols = 4);

    int minSymbols() const { return _minSymbols; }

private:
    int _minSymbols;
};

class PlateDetector {
public:
    std::vector<sp<NumberPlate>> detectPlate(const std::vector<ExtremalRegion> &detectedSymbols) const;

private:
    Quad buildBoundingQuad(const Rectangle &rightSymbol, const Rectangle &leftSymbol) const;

    std::vector<Rectangle> groupNestedRegions(std::vector<Rectangle> const& regions) const;

public:
    std::vector<std::vector<Rectangle>> groupRegions(const std::vector<Rectangle> &rects) const;
    std::vector<std::vector<Rectangle>> groupBySize(const std::vector<Rectangle> &rects) const;
    std::vector<std::vector<Rectangle>> groupByDistance(const std::vector<Rectangle> &rects) const;
    std::vector<std::vector<Rectangle>> groupBy(
            const std::vector<Rectangle> &allRegions,
            std::function<bool (const Rectangle&, const Rectangle&)> compareFunc,
            std::function<bool (const Rectangle&, const Rectangle&)> proximityFunc) const;

    std::vector<Rectangle> findGroup(
            int *outIndex,
            const std::vector<Rectangle> &sorted,
            int baseIndex,
            std::function<bool (const Rectangle&, const Rectangle&)> proximityFunc) const;

    std::vector<std::vector<Rectangle>> findIntersections(
            const std::vector<std::vector<Rectangle>> &groups1,
            const std::vector<std::vector<Rectangle>> &groups2) const;

    std::vector<Rectangle> intersect(const std::vector<Rectangle> &one, const std::vector<Rectangle> &another) const;
};

}

#endif // RS_PLATEDETECTOR_H
