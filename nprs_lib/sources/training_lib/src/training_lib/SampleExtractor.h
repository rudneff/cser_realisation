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
    std::vector<Sample> extractPositiveSample(const Bitmap &image);
    std::vector<Sample> extractPositiveSample(const Image &image);

    std::vector<Sample> extractNegativeSample(const Image &image, bool isSceneImage);
};

}

#endif // SYMBOL_FEATURE_EXTRACTOR_H
