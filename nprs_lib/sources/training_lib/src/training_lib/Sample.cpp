#include "Sample.h"

using namespace nprs;

Sample::Sample(const std::vector<float> &features, SampleType type, sp<const Image> image)
    : _image(image), _featureVector(features), _sampleType(type)
{
}
