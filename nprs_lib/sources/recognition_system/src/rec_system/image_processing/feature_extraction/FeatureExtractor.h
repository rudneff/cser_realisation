#ifndef RS_FEATUREEXTRACTOR_H
#define RS_FEATUREEXTRACTOR_H

#include <common/NprsStd.h>
#include <vector>
#include <common/image/Image.h>
#include <common/Rectangle.h>

namespace nprs {

class Image;
class Rectangle;

class FeatureExtractor {
public:
    virtual ~FeatureExtractor() {}

    virtual std::vector<float> extract(const Image &image, int channel, const Rectangle &bounds) = 0;
};

}

#endif // RS_FEATUREEXTRACTOR_H
