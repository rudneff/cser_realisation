#ifndef TRAININGLIB_SAMPLE_H
#define TRAININGLIB_SAMPLE_H

#include <common/NprsStd.h>
#include <rec_system/classification/TrainingSet.h>
#include <common/image/Image.h>

namespace nprs {

enum class SampleType {
    NMHeavy, NMLight
};

class Sample final {
public:
    Sample(const std::vector<float> &features, SampleType type, sp<const Image> image = sp<const Image>());

    const std::vector<float> & featureVector() const { return _featureVector; }
    sp<const Image> image() const { return _image; }
    SampleType type() const { return _sampleType; }

private:
    SampleType _sampleType; 
    std::vector<float> _featureVector;
    sp<const Image> _image;
};

}

#endif // TRAININGLIB_SAMPLE_H
