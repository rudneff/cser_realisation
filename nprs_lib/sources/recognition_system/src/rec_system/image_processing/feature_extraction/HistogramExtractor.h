#ifndef RS_HISTOGRAMEXTRACTOR_H
#define RS_HISTOGRAMEXTRACTOR_H

#include <rec_system/image_processing/feature_extraction/FeatureExtractor.h>
#include <common/image/Image.h>
#include <common/Rectangle.h>

namespace nprs {
    
class HistogramExtractor : public FeatureExtractor {
public:
    HistogramExtractor(int numBins);

    virtual std::vector<float> extract(const Image &image, int channel, const Rectangle &bounds) override;

private:
    int _numBins;
};

}

#endif // RS_HISTOGRAMEXTRACTOR_H
