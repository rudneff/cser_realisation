#include "PlateDetector.h"

#include <common/Rectangle.h>
#include <map>
#include "region_detection/cser/ExtremalRegion.h"
#include <rec_system/common_structures/NumberPlate.h>
#include <rec_system/common_structures/NumberPlateCharacter.h>
#include <common/math/Math.h>
#include <common/exceptions/CommonExceptions.h>
#include "HoughLineDetector.h"
#include <iostream>

namespace nprs {

static void dbgPrintGroup(std::vector<Rectangle> const& group) {
    std::cout << "{" << std::endl;
    for (Rectangle rect: group) {
        std::cout << "    {x: " << rect.x() << " y: " << rect.y() << " w: " << rect.width() << " h: " << rect.height() << "}" << std::endl;
    }
    std::cout << "}" << std::endl;
}

static void dbgPrintGroups(std::vector<std::vector<Rectangle>> const& groups) {
    std::cout << "------------------------" << std::endl;
    for (auto group: groups) {
        dbgPrintGroup(group);
    }
    std::cout << std::endl;
}

std::vector<sp<NumberPlate>> PlateDetector::detectPlate(
    const std::vector<ExtremalRegion> &detectedSymbols) const
{
    std::vector<Rectangle> regions;
    for (ExtremalRegion er: detectedSymbols) {
        regions.push_back(er.bounds());
    }
//
//    auto groupedSymbols = groupRegions(groupNestedRegions(regions));
//
//    std::vector<sp<NumberPlate>> plates;
//    for (auto group: groupedSymbols) {
//        std::vector<sp<NumberPlateCharacter>> characters;
//        std::sort(
//            group.begin(), group.end(),
//            [] (const Rectangle &r1, const Rectangle &r2) {
//                return r1.middlePoint().x() < r2.middlePoint().x();
//            });
//
//        for (auto reg: group) {
//            if (group.size() > 4) {
//                sp<NumberPlateCharacter> character = sp<NumberPlateCharacter>(new NumberPlateCharacter(0, reg));
//                characters.push_back(character);
//            }
//        }
//        plates.push_back(sp<NumberPlate>(new NumberPlate(characters, Quad(), Line(), Rectangle())));
//    }
//
//    return plates;

//    std::vector<std::vector<Rectangle>> groupsBySize = groupBySize(regions);

    std::vector<std::vector<Rectangle>> groups = findRegionsOnLine(regions);

    std::vector<sp<NumberPlate>> numberPlates;
    for (std::vector<Rectangle> const& group : groups) {
        std::vector<sp<NumberPlateCharacter>> chars;
        for (Rectangle rec: group) {
            chars.push_back(sp<NumberPlateCharacter>(new NumberPlateCharacter(0, rec)));
        }
        numberPlates.push_back(sp<NumberPlate>(new NumberPlate(chars, Quad(), Line())));
    }

    return numberPlates;
}

std::vector<std::vector<Rectangle>> PlateDetector::findRegionsOnLine(const std::vector<Rectangle> &regions) const {
    std::vector<Point> symbolCenters;
    std::map<Point, Rectangle> regionMap;
    std::vector<Rectangle> filtered = regions;
    for (Rectangle const& s: filtered) {
        symbolCenters.push_back(s.middlePoint());
        regionMap[s.middlePoint()] = s;
    }
    
    LineDetectorParameters lineDetectorParameters(0, 0, 180, 300, 0, 0);
    HoughLineDetector lineDetector(lineDetectorParameters);

    std::vector<LineDetectorResult> detectedLines = lineDetector.perform(symbolCenters);
    std::vector<std::vector<Rectangle>> results;
    for (LineDetectorResult line: detectedLines) {
        std::vector<Rectangle> groupedRects;
        for (Point p: line.points()) {
            groupedRects.push_back(regionMap[p]);
        };
        results.push_back(groupedRects);
    }

    return results;
}

Quad PlateDetector::buildBoundingQuad(const Rectangle &rightSymbol, const Rectangle &leftSymbol) const {
    return Quad(
        Point(rightSymbol.x(), rightSymbol.y()),
        Point(rightSymbol.x(), rightSymbol.y1()),
        Point(leftSymbol.x1(), leftSymbol.y1()),
        Point(leftSymbol.x1(), leftSymbol.y()));
}

std::vector<Rectangle> PlateDetector::groupNestedRegions(std::vector<Rectangle> const &regions) const {
//    throw NotImplementedException("PlateDetector::groupNestedRegions()");

    std::vector<Rectangle> sorted = regions;

    std::sort(
        sorted.begin(),
        sorted.end(),
        [] (const Rectangle &r1, const Rectangle &r2) { return r1.middlePoint().x() < r2.middlePoint().x(); }
    );

    std::vector<Rectangle> result;
    for (int i = 0; i < sorted.size(); i++) {
        Rectangle r1 = sorted[i];
        result.push_back(sorted[i]);

        bool shouldStop = false;
        for (int j = i + 1; j < sorted.size() && !shouldStop; j++) {
            Rectangle r2 = sorted[j];
            if (Math::abs(r2.middlePoint().x() - r1.middlePoint().x()) < 5) {
                if (Math::abs(r2.middlePoint().y() - r1.middlePoint().y()) < 5 &&
                    Math::max(r1.width(), r2.width()) / Math::min(r1.width(), r2.width()) < 1.5 &&
                    Math::max(r1.height(), r2.height()) / Math::min(r1.height(), r2.height()) < 1.5)
                {
                    i += 1;
                }
            }
            else {
                shouldStop = true;
            }
        }
    }

    return result;
}

std::vector<std::vector<Rectangle>> PlateDetector::groupRegions(const std::vector<Rectangle> &rects) const {
    auto regionsGroupedBySize = groupBySize(rects);
    
    std::cout << "groups by size: " << std::endl;
    dbgPrintGroups(regionsGroupedBySize);

    std::vector<std::vector<Rectangle>> result;
    for (auto sizeGroup: regionsGroupedBySize) {
        auto distGroups = groupByDistance(sizeGroup);
        
        std::cout << "group by distance (intersection)" << std::endl;
        dbgPrintGroups(distGroups);
        
        result.insert(result.end(), distGroups.begin(), distGroups.end());
    }

    return result;
}

std::vector<std::vector<Rectangle>> PlateDetector::groupByDistance(const std::vector<Rectangle> &rects) const {
    std::cout << "group by distance:" << std::endl;

    auto horizontalGroups = groupBy(
        rects,
        [] (const Rectangle &r1, const Rectangle &r2) { return r1.middlePoint().x() < r2.middlePoint().x(); },
        [] (const Rectangle &r1, const Rectangle &r2) {
            return (Math::abs(r1.middlePoint().x() - r2.middlePoint().x()) < r1.width() * 2) &&
                   (r1.middlePoint().distanceTo(r2.middlePoint()) < r1.width() * 2);
        }
    );
    
    std::cout << "horizontal groups" << std::endl;
    dbgPrintGroups(horizontalGroups);

    auto verticalGroups = groupBy(
        rects,
        [] (const Rectangle &r1, const Rectangle &r2) { return r1.middlePoint().y() < r2.middlePoint().y(); },
        [] (const Rectangle &r1, const Rectangle &r2) {
            return (Math::abs(r1.middlePoint().y() - r2.middlePoint().y()) < r1.height() * 2) &&
                   (r1.middlePoint().distanceTo(r2.middlePoint()) < r1.height() * 2);
        }
    );
    
    std::cout << "vertical groups" << std::endl;
    dbgPrintGroups(verticalGroups);

    return findIntersections(verticalGroups, horizontalGroups);
}

std::vector<std::vector<Rectangle>> PlateDetector::groupBySize(const std::vector<Rectangle> &rects) const {
    auto groupedByWidth = groupBy(
        rects,
        [] (const Rectangle &r1, const Rectangle &r2) { return  r1.width() < r2.width(); },
        [] (const Rectangle &r1, const Rectangle &r2)  {
            return Math::max(r1.width(), r2.width()) / Math::min(r1.width(), r2.width()) < 1.5;
        });

    auto groupedByHeight = groupBy(
        rects,
        [] (const Rectangle &r1, const Rectangle &r2) { return  r1.height() < r2.height(); },
        [] (const Rectangle &r1, const Rectangle &r2)  {
            return Math::max(r1.height(), r2.height()) / Math::min(r1.height(), r2.height()) < 1.5;
        });

    return findIntersections(groupedByWidth, groupedByHeight);
}

std::vector<std::vector<Rectangle>> PlateDetector::groupBy(
        const std::vector<Rectangle> &allRegions,
        std::function<bool(const Rectangle &, const Rectangle &)> compareFunc,
        std::function<bool(const Rectangle &, const Rectangle &)> proximityFunc) const
{
    if (allRegions.size() <= 1) {
        return { allRegions };
    }

    std::vector<Rectangle> sorted = allRegions;
    std::sort(sorted.begin(), sorted.end(), compareFunc);

    std::vector<std::vector<Rectangle>> results;
    int i = 0;
    do {
        results.push_back(findGroup(&i, sorted, i, proximityFunc));
    }
    while (i < sorted.size() - 1);

    return results;
}

std::vector<Rectangle> PlateDetector::findGroup(
        int *outIndex,
        const std::vector<Rectangle> &sorted,
        int baseIndex,
        std::function<bool(const Rectangle &, const Rectangle &)> proximityFunc) const
{
    std::vector<Rectangle> currGroup = { sorted[baseIndex] };
    bool groupEnded = false;

    int oi = baseIndex;
    for (int i = baseIndex; i < sorted.size() - 1 && !groupEnded; i++) {
        Rectangle r1 = sorted[i];
        Rectangle r2 = sorted[i + 1];

        if (proximityFunc(r1, r2)) {
            currGroup.push_back(r2);
        }
        else {
            groupEnded = true;
        }
        oi = i + 1;
    }

    *outIndex = oi;
    return currGroup;
}

std::vector<std::vector<Rectangle>> PlateDetector::findIntersections(
        const std::vector<std::vector<Rectangle>> &groups1,
        const std::vector<std::vector<Rectangle>> &groups2) const
{
    std::vector<std::vector<Rectangle>> result;

    for (auto group: groups1) {
        for (auto group2: groups2) {
            result.push_back(intersect(group, group2));
        }
    }

    return result;
}


// -------------------------------------------------------------------------------------------------------------------

PlateDetectorParams::PlateDetectorParams(int minSymbols)
: _minSymbols(minSymbols)
{
}

std::vector<Rectangle> PlateDetector::intersect(const std::vector<Rectangle> &one, const std::vector<Rectangle> &another) const {
    std::vector<Rectangle> res;

    for (Rectangle oneRec: one) {
        for (Rectangle anotherRec: another) {
            if (oneRec == anotherRec) {
                res.push_back(oneRec);
            }
        }
    }

    return res;
}

}
