#ifndef POSITIVESYMBOLINPUTSAMPLE_H
#define POSITIVESYMBOLINPUTSAMPLE_H

#include <training_lib/input_samples/ImageInputSample.h>

namespace nprs {

class PositiveImageInputSample : public ImageInputSample {
public:
    explicit PositiveImageInputSample(sp<const Image> image);

    sp<SampleExtractor> createExtractor() const override;
};

}

#endif // POSITIVESYMBOLINPUTSAMPLE_H
