#ifndef TRAININGLIB_RANDOMSCENEREGIONEXTRACTOR_H
#define TRAININGLIB_RANDOMSCENEREGIONEXTRACTOR_H

#include <random>
#include <training_lib/SampleExtractor.h>
#include <common/Size.h>
#include <common/Rectangle.h>

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
    std::vector<Sample> extractNMHeavySamples() override;

private:
    sp<const Image> _image;
    int _numSamples;
    Size _minSize;
    Size _maxSize;

    Rectangle chooseRandomRegion();
    bool checkConstraints(const ExtremalRegion &reg);
    
    std::default_random_engine _rng;
    std::uniform_int_distribution<int> _widthDist;
    std::uniform_int_distribution<int> _heightDist;
};

}

#endif // TRAININGLIB_RANDOMSCENEREGIONEXTRACTOR_H
