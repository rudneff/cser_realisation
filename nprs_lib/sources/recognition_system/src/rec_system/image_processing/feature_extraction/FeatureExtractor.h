#ifndef RS_FEATUREEXTRACTOR_H
#define RS_FEATUREEXTRACTOR_H

#include <common/NprsStd.h>
#include <vector>

namespace nprs {

class Image;
class Rectangle;

class FeatureExtractor {
public:
    virtual std::vector<float> extract(const Image &image, const Rectangle &bounds) = 0;
};

}

#endif // RS_FEATUREEXTRACTOR_H
