#ifndef SYMBOL_FEATURE_EXTRACTOR_H
#define SYMBOL_FEATURE_EXTRACTOR_H

#include <tuple>
#include <vector>

namespace nprs {

class Sample;
class Bitmap;
class Image;
class ExtremalRegion;

class SampleExtractor {
public:
    std::vector<Sample> extractPositiveSample(const Bitmap &image, int numImages = 10);
    std::vector<Sample> extractPositiveSample(const Image &image, int numImages = 10);
};

}

#endif // SYMBOL_FEATURE_EXTRACTOR_H
