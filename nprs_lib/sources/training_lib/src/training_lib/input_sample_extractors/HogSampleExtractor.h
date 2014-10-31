#ifndef TL_HOGEXTRACTOR_H
#define TL_HOGEXTRACTOR_H

#include <training_lib/SampleExtractor.h>

namespace nprs {

class HogSampleExtractor : public SampleExtractor {
public:
    HogSampleExtractor(sp<const Image> const& image);

    std::vector<Sample> extractSamples() override;

private:
    sp<const Image> _image;
};

}

#endif // TL_HOGEXTRACTOR_H
