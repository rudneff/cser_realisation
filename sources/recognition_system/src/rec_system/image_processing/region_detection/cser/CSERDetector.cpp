#include "CSERDetector.h"
#include "ExtremalRegion.h"

nprs::CSERDetector::CSERDetector(std::vector<pERFilter> const& filters)
    : _filters(filters)
{
    
}

nprs::CSERDetector::~CSERDetector() {
    
}

std::vector<nprs::ExtremalRegion> nprs::CSERDetector::detect(Image<uchar> const& image) {
    return std::vector<ExtremalRegion>();
}