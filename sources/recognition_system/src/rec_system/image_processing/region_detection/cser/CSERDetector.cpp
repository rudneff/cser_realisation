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

    Matrix<pERDescriptor> erMap(image.width(), image.height());
    CserContext ctx;
    ctx.erMap = &erMap;
    for (int i = 0; i < 255; i++) {
        
    }
}
