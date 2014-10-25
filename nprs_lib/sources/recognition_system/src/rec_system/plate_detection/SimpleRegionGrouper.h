#ifndef RS_SIMPLEREGIONGROUPER_H
#define RS_SIMPLEREGIONGROUPER_H

#include <rec_system/plate_detection/region_detection/cser/ExtremalRegion.h>
#include "RegionGrouper.h"

namespace nprs {

class SimpleRegionGrouper: public RegionGrouper {
public:
    SimpleRegionGrouper();

    virtual std::vector<std::vector<ExtremalRegion>> groupRegions(const std::vector<ExtremalRegion> &regions) const;

private:
    int findNeighbor(const ExtremalRegion &reg, const std::vector<ExtremalRegion> &regions) const;
    std::vector<std::vector<ExtremalRegion>> groupBySize(const std::vector<ExtremalRegion> &rects) const;

    std::vector<ExtremalRegion> groupNestedRegions(
        std::vector<ExtremalRegion> const &regions) const;

    std::vector<std::vector<ExtremalRegion>> groupBy(
            const std::vector<ExtremalRegion> &allRegions,
            std::function<bool(const ExtremalRegion &, const ExtremalRegion &)> compareFunc,
            std::function<bool(const ExtremalRegion &, const ExtremalRegion &)> proximityFunc) const;

    std::vector<ExtremalRegion> findGroup(
            int *outIndex,
            const std::vector<ExtremalRegion> &sorted,
            int baseIndex,
            std::function<bool(const ExtremalRegion &, const ExtremalRegion &)> proximityFunc) const;

    std::vector<std::vector<ExtremalRegion>> findIntersections(
        const std::vector<std::vector<ExtremalRegion>> &groups1,
        const std::vector<std::vector<ExtremalRegion>> &groups2) const;

    std::vector<ExtremalRegion> intersect(
        const std::vector<ExtremalRegion> &one,
        const std::vector<ExtremalRegion> &another) const;
};

}

#endif // RS_SIMPLEREGIONGROUPER_H
