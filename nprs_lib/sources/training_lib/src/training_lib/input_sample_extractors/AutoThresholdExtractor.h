#ifndef TRAININGLIB_POSITIVESYMBOLSAMPLEEXTRACTOR_H
#define TRAININGLIB_POSITIVESYMBOLSAMPLEEXTRACTOR_H

#include <common/image/Image.h>
#include <training_lib/SampleExtractor.h>

namespace nprs {

class Image;

class AutoThresholdExtractor : public SampleExtractor {
public:
    explicit AutoThresholdExtractor(sp<const Image> image);
    ~AutoThresholdExtractor();

    std::vector<Sample> extractNMLightSamples() override;

private:
    sp<const Image> _image;
};

}

#endif // TRAININGLIB_POSITIVESYMBOLSAMPLEEXTRACTOR_H

