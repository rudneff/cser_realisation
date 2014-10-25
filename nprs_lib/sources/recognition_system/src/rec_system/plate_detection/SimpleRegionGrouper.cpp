#include "SimpleRegionGrouper.h"

#include "region_detection/cser/ExtremalRegion.h"
#include <common/Point.h>
#include <vector>

using std::vector;

namespace nprs {

SimpleRegionGrouper::SimpleRegionGrouper() {

}

vector<vector<ExtremalRegion>> SimpleRegionGrouper::groupRegions(const vector<ExtremalRegion> &regions) const {
    std::vector<ExtremalRegion> filteredNested = groupNestedRegions(regions);
    std::vector<std::vector<ExtremalRegion>> groupsBySize = groupBySize(filteredNested);

    for (std::vector<ExtremalRegion> const& group: groupsBySize) {

    }

    return groupsBySize;
}

std::vector<ExtremalRegion> SimpleRegionGrouper::groupNestedRegions(std::vector<ExtremalRegion> const &regions) const {
    std::vector<ExtremalRegion> sorted = regions;

    std::sort(
        sorted.begin(),
        sorted.end(),
        [] (const ExtremalRegion &r1, const ExtremalRegion &r2) {
            return r1.bounds().middlePoint().x() < r2.bounds().middlePoint().x();
        }
    );

    std::vector<ExtremalRegion> result;
    for (int i = 0; i < sorted.size(); i++) {
        Rectangle r1 = sorted[i].bounds();
        result.push_back(sorted[i]);

        bool shouldStop = false;
        for (int j = i + 1; j < sorted.size() && !shouldStop; j++) {
            Rectangle r2 = sorted[j].bounds();
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

int SimpleRegionGrouper::findNeighbor(const ExtremalRegion &reg, const std::vector<ExtremalRegion> &regions) const {
    std::vector<ExtremalRegion> filtered = regions;
    std::remove_if(
        filtered.begin(), filtered.end(),
        [&] (const ExtremalRegion &r) {
            return reg == r ||
            r.bounds().middlePoint().distanceTo(reg.bounds().middlePoint()) > reg.bounds().width() * 2;
        });

}

std::vector<std::vector<ExtremalRegion>> SimpleRegionGrouper::groupBySize(const std::vector<ExtremalRegion> &rects) const {
    auto groupedByWidth = groupBy(
        rects,
        [] (const ExtremalRegion &r1, const ExtremalRegion &r2) {
            return  r1.bounds().width() < r2.bounds().width();
        },

        [] (const ExtremalRegion &r1, const ExtremalRegion &r2)  {
            return Math::max(r1.bounds().width(), r2.bounds().width()) / Math::min(r1.bounds().width(), r2.bounds().width()) < 1.5;
        });

    auto groupedByHeight = groupBy(
        rects,
        [] (const ExtremalRegion &r1, const ExtremalRegion &r2) {
            return  r1.bounds().height() < r2.bounds().height();
        },

        [] (const ExtremalRegion &r1, const ExtremalRegion &r2)  {
            return Math::max(r1.bounds().height(), r2.bounds().height()) / Math::min(r1.bounds().height(), r2.bounds().height()) < 1.5;
        });

    return findIntersections(groupedByWidth, groupedByHeight);
}

std::vector<std::vector<ExtremalRegion>> SimpleRegionGrouper::groupBy(
        const std::vector<ExtremalRegion> &allRegions,
        std::function<bool(const ExtremalRegion &, const ExtremalRegion &)> compareFunc,
        std::function<bool(const ExtremalRegion &, const ExtremalRegion &)> proximityFunc) const
{
    if (allRegions.size() <= 1) {
        return { allRegions };
    }

    std::vector<ExtremalRegion> sorted = allRegions;
    std::sort(sorted.begin(), sorted.end(), compareFunc);

    std::vector<std::vector<ExtremalRegion>> results;
    int i = 0;
    do {
        results.push_back(findGroup(&i, sorted, i, proximityFunc));
    }
    while (i < sorted.size() - 1);

    return results;
}

std::vector<ExtremalRegion> SimpleRegionGrouper::findGroup(
        int *outIndex,
        const std::vector<ExtremalRegion> &sorted,
        int baseIndex,
        std::function<bool(const ExtremalRegion &, const ExtremalRegion &)> proximityFunc) const
{
    std::vector<ExtremalRegion> currGroup = { sorted[baseIndex] };
    bool groupEnded = false;

    int oi = baseIndex;
    for (int i = baseIndex; i < sorted.size() - 1 && !groupEnded; i++) {
        ExtremalRegion r1 = sorted[i];
        ExtremalRegion r2 = sorted[i + 1];

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

std::vector<std::vector<ExtremalRegion>> SimpleRegionGrouper::findIntersections(
        const std::vector<std::vector<ExtremalRegion>> &groups1,
        const std::vector<std::vector<ExtremalRegion>> &groups2) const
{
    std::vector<std::vector<ExtremalRegion>> result;

    for (auto group: groups1) {
        for (auto group2: groups2) {
            result.push_back(intersect(group, group2));
        }
    }

    return result;
}

std::vector<ExtremalRegion> SimpleRegionGrouper::intersect(
        const std::vector<ExtremalRegion> &one,
        const std::vector<ExtremalRegion> &another) const
{
    std::vector<ExtremalRegion> res;

    for (ExtremalRegion const& oneRec: one) {
        for (ExtremalRegion const& anotherRec: another) {
            if (oneRec == anotherRec) {
                res.push_back(oneRec);
            }
        }
    }

    return res;
}

}
