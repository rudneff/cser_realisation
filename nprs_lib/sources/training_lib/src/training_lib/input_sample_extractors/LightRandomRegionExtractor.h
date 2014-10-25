#ifndef TL_LIGHTRANDOMREGIONEXTRACTOR_H
#define TL_LIGHTRANDOMREGIONEXTRACTOR_H

#include "RandomRegionExtractor.h"

namespace nprs {

class LightRandomRegionExtractor: public RandomRegionExtractor {
public:
    LightRandomRegionExtractor(
            sp<const Image> const& image,
            int numSamples,
            Size const &minSize,
            Size const &maxSize);

    virtual std::vector<Sample> extractSamples() override;
};

}

#endif // TL_LIGHTRANDOMREGIONEXTRACTOR_H
