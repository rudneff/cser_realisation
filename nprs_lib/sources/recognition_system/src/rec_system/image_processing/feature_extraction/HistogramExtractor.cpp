#include "HistogramExtractor.h"
#include <common/exceptions/ArgumentException.h>
#include <iostream>

namespace nprs {

HistogramExtractor::HistogramExtractor(int numBins)
: _numBins(numBins)
{}

std::vector<float> HistogramExtractor::extract(const Image &image, int channel, const Rectangle &bounds) {
    float min, max;
    image.computeRange(&min, &max, channel);

//    std::cout << "range: " << min << " - " << max << std::endl;

    std::vector<float> bins(_numBins, 0.0f);
    for (int x = (int) bounds.x(); x < bounds.x1(); x++) {
        for (int y = (int) bounds.y(); y < bounds.y1(); y++) {
            float pixValue = image(x, y, channel);
            int bin = (int) (pixValue * _numBins);
            
            if (bin >= bins.size() || bin < 0)
                std::cout << "HistogramExtractor::extract(): bin was greater than bins count. bin - " << bin << " pix value - " << pixValue << std::endl;
            
            bins[bin] = bins[bin] + 1.0f;
        }
    }

    return bins;
}

}
