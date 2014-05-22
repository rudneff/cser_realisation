#include "CSERDetector.h"
#include "ExtremalRegion.h"
#include "ERDescriptor.h"
#include "common/image/Color.h"
#include "common/exceptions/NotSupportedException.h"

nprs::CSERDetector::CSERDetector(std::vector<pERFilter> const& filters)
    : _filters(filters)
{
    
}

nprs::CSERDetector::~CSERDetector() {
}

std::vector<nprs::ExtremalRegion> nprs::CSERDetector::detect(Image<uchar> const& image) {
    if (image.getColorInfo().format() != COLORFORMAT_I255) {
        throw NotSupportedException("CSERDetector::detect(): Only I255 ColorFormat supported for this algorithm");
    }

    Matrix<pERDescirptor> erMap(image.width(), image.height());
    for (int i = 0; i < 255; i++) {
        
    }
}

nprs::ERDescriptor nprs::CSERDetector::newRegion(Point const& p) {
}

nprs::ERDescriptor nprs::CSERDetector::mergeRegions(ERDescriptor const& r1, ERDescriptor const& r2) {
}

nprs::ERDescriptor nprs::CSERDetector::addPointToRegion(Point const& p) {
}
