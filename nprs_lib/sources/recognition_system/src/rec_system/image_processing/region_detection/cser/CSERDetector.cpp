#include "CSERDetector.h"
#include "ExtremalRegion.h"
#include "ERDescriptor.h"
#include "common/image/Color.h"
#include "common/exceptions/NotSupportedException.h"
#include <rec_system/image_processing/region_detection/cser/algorithm/CserAlgorithm.h>

nprs::CSERDetector::CSERDetector(std::vector<pERFilter> const& filters)
    : _filters(filters)
{
}

nprs::CSERDetector::~CSERDetector() {
}

std::vector<nprs::ExtremalRegion> nprs::CSERDetector::detect(Image<uchar> const& image) {
    if (image.getColorInfo().format() != ColorFormat::I255) {
        throw NotSupportedException("CSERDetector::detect(): Only I255 ColorFormat supported for this algorithm");
    }

    
    CserAlgorithm algorithm(image, 0, _filters);
    std::vector<ERDescriptor*> descriptors = algorithm.perform();
    std::vector<ExtremalRegion> result;
    for (auto desc : descriptors) {
        result.push_back(ExtremalRegion(desc));
    }

    return result;
}
