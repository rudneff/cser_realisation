#include "HistogramExtractor.h"
#include <common/image/Image.h>
#include <common/Rectangle.h>

namespace nprs {

HistogramExtractor::HistogramExtractor(int numBins, int channel) 
: _numBins(numBins), _channel(channel)
{}

std::vector<float> HistogramExtractor::extract(Image const& image, Rectangle const& bounds) {
    std::vector<float> bins(_numBins);
    for (int x = bounds.x(); x < bounds.x1(); x++) {
        for (int y = bounds.x(); y < bounds.y1(); y++) {
            int bin = image(x, y, _channel) * _numBins;
            bins[bin] += 1.0f;
        }
    }
    return bins;
}

}
