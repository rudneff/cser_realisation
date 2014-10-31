#include "HogSampleExtractor.h"

#include <rec_system/image_processing/feature_extraction/HogFeatureExtractor.h>

namespace nprs {

HogSampleExtractor::HogSampleExtractor(sp<const Image> const &image)
: _image(image)
{

}

std::vector<Sample> HogSampleExtractor::extractSamples() {
    HogFeatureExtractor extractor;
    std::vector<float> fv = extractor.extract(*_image, 0, Rectangle(0, 0, _image->width(), _image->height()));
    return {Sample(fv, SampleType::NMHeavy)};
}

}
