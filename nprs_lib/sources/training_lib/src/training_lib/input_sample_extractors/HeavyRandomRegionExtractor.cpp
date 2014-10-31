#include "HeavyRandomRegionExtractor.h"
#include "AutoThresholdExtractor.h"
#include "HogSampleExtractor.h"
#include <rec_system/plate_detection/region_detection/cser/ERFilter.h>
#include <rec_system/plate_detection/region_detection/cser/CSERDetector.h>

namespace nprs {

HeavyRandomRegionExtractor::HeavyRandomRegionExtractor(
        sp<const Image> const& image,
        int numSamples,
        Size const &minSize,
        Size const &maxSize)
    : RandomRegionExtractor(image, numSamples, minSize, maxSize)
{
}

std::vector<Sample> HeavyRandomRegionExtractor::extractSamples() {
    CSERDetector detector(std::vector<sp<ERFilter>>());
    std::vector<Sample> result;

    for (int i = 0; i < numSamples(); i++) {
        Rectangle bounds = chooseRandomRegion();
        auto regionImage = std::make_shared<Image>(image()->cropped(bounds));
        HogSampleExtractor extractor(regionImage);
        std::vector<Sample> extractedSamples = extractor.extractSamples();
        for (Sample const& sample : extractedSamples) {
            result.push_back(sample);
        }
    }

    return result;
}

}
