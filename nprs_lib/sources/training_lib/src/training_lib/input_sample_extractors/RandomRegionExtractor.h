#ifndef TRAININGLIB_RANDOMSCENEREGIONEXTRACTOR_H
#define TRAININGLIB_RANDOMSCENEREGIONEXTRACTOR_H

#include <training_lib/SampleExtractor.h>
#include <common/Size.h>

namespace nprs {

class Image;
class ExtremalRegion;

class RandomRegionExtractor : public SampleExtractor {
public:
    RandomRegionExtractor(
            sp<const Image> image,
            int numSamples,
            const Size &minSize = 0,
            const Size &maxSize = 0);

    std::vector<Sample> extractNMLightSamples() override;

private:
    sp<const Image> _image;
    int _numSamples;
    Size _minSize;
    Size _maxSize;

    bool checkConstraints(const ExtremalRegion &reg);
};

}

#endif // TRAININGLIB_RANDOMSCENEREGIONEXTRACTOR_H
