#ifndef POSITIVESYMBOLINPUTSAMPLE_H
#define POSITIVESYMBOLINPUTSAMPLE_H

#include <training_lib/input_samples/ImageInputSample.h>

namespace nprs {

class PositiveImageInputSample : public ImageInputSample {
public:
    explicit PositiveImageInputSample(sp<const Image> image);

private:
    up<SampleExtractor> createLightSampleExtractor() const override;
    up<SampleExtractor> createHeavySampleExtractor() const override;
};

}

#endif // POSITIVESYMBOLINPUTSAMPLE_H
