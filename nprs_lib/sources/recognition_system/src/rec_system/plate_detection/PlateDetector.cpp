#include "PlateDetector.h"

#include <common/Rectangle.h>
#include <map>
#include "region_detection/cser/ExtremalRegion.h"
#include <rec_system/common_structures/NumberPlate.h>
#include <rec_system/common_structures/NumberPlateCharacter.h>
#include "HoughLineDetector.h"

namespace nprs {

std::vector<sp<NumberPlate>> PlateDetector::detectPlate(
    const std::vector<ExtremalRegion> &detectedSymbols) const
{
    std::vector<Point> symbolCenters;
    std::map<Point, Rectangle> regionMap;

    for (auto const& s: detectedSymbols) {
        symbolCenters.push_back(s.bounds().middlePoint());
        regionMap[s.bounds().middlePoint()] = s.bounds();
    }

    LineDetectorParameters lineDetectorParameters(0, 0, 18, 200, 10, 0);
    HoughLineDetector lineDetector(lineDetectorParameters);

    std::vector<LineDetectorResult> detectedLines = lineDetector.perform(symbolCenters);
    std::vector<sp<NumberPlate>> results;
    for (auto line: detectedLines) {
        std::vector<sp<NumberPlateCharacter>> chars;
        auto points = line.points();

        for (auto p: line.points()) {
            chars.push_back(std::make_shared<NumberPlateCharacter>(0, regionMap[p]));
        };

        Point rightPoint = *std::min_element(
            points.begin(), points.end(), [] (Point &p1, Point &p2) { return p1.x() < p2.x(); });

        Point leftPoint = *std::max_element(
            points.begin(), points.end(), [] (Point &p1, Point &p2) { return p1.x() < p2.x(); });

        Rectangle region1 = regionMap[rightPoint];
        Rectangle region2 = regionMap[leftPoint];

        Quad boundingQuad = buildBoundingQuad(regionMap[rightPoint], regionMap[leftPoint]);

        results.push_back(sp<NumberPlate>(new NumberPlate(chars, boundingQuad, line.line())));
    }

    return results;
}

Quad PlateDetector::buildBoundingQuad(const Rectangle &rightSymbol, const Rectangle &leftSymbol) const {
    return Quad(
        Point(rightSymbol.x(), rightSymbol.y() < leftSymbol.y() ? rightSymbol.y() : rightSymbol.y1()),
        Point(rightSymbol.x(), rightSymbol.y() < leftSymbol.y() ? rightSymbol.y1() : rightSymbol.y()),
        Point(leftSymbol.x1(), leftSymbol.y() > rightSymbol.y() ? leftSymbol.y1() : leftSymbol.y()),
        Point(leftSymbol.x1(), leftSymbol.y() > rightSymbol.y() ? leftSymbol.y() : leftSymbol.y1()));
}

}
