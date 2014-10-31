#ifndef RS_HEAVYRANDOMREGIONEXTRACTOR_H
#define RS_HEAVYRANDOMREGIONEXTRACTOR_H

#include "RandomRegionExtractor.h"

namespace nprs {

class HeavyRandomRegionExtractor: public RandomRegionExtractor {
public:
    HeavyRandomRegionExtractor(sp<const Image> const& image, int numSamples, Size const &minSize, Size const &maxSize);

    virtual std::vector<Sample> extractSamples();
};

}

#endif // RS_HEAVYRANDOMREGIONEXTRACTOR_H
