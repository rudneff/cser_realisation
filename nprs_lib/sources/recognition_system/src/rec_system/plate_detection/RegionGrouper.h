#ifndef RS_REGIONGROUPER_H
#define RS_REGIONGROUPER_H

#include <vector>

namespace nprs {

class ExtremalRegion;

class RegionGrouper {
public:
    virtual ~RegionGrouper() {}

    virtual std::vector<std::vector<ExtremalRegion>> groupRegions(const std::vector<ExtremalRegion> &regions) const = 0;
};

}

#endif // RS_REGIONGROUPER_H
