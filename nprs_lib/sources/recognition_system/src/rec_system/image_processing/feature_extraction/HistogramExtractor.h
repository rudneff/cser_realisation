#ifndef RS_HISTOGRAMEXTRACTOR_H
#define RS_HISTOGRAMEXTRACTOR_H

#include <rec_system/image_processing/feature_extraction/FeatureExtractor.h>

namespace nprs {
    
class HistogramExtractor : public FeatureExtractor {
public:
    HistogramExtractor(int numBins, int channel);

    virtual std::vector<float> extract(Image const& image, Rectangle const& bounds) override;

private:
    int _numBins;
    int _channel;
    bool _normalized;
};

}

#endif // RS_HISTOGRAMEXTRACTOR_H
