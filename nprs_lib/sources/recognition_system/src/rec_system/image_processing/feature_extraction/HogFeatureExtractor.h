#ifndef RS_HOGFEATUREEXTRACTOR_H
#define RS_HOGFEATUREEXTRACTOR_H

#include "FeatureExtractor.h"
#include <common/image/Image.h>
#include <rec_system/image_processing/SobelOperator.h>
#include <rec_system/image_processing/feature_extraction/HistogramExtractor.h>

namespace nprs {

class HogFeatureExtractor : public FeatureExtractor {
public:
    HogFeatureExtractor();

    std::vector<float> extract(const Image &image, int channel, const Rectangle &bounds) override;

private:
    up<GradientOperator> _gradientOperator;

    std::vector<float> calcHog(const Image &gradients, int channel, Rectangle bounds);
};

}

#endif // RS_HOGFEATUREEXTRACTOR_H
