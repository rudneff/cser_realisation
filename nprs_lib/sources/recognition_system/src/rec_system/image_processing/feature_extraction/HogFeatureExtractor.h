#ifndef RS_HOGFEATUREEXTRACTOR_H
#define RS_HOGFEATUREEXTRACTOR_H

#include "FeatureExtractor.h"

namespace nprs {

class HogFeatureExtractor : public FeatureExtractor {
public:
    virtual std::vector<float> extract(const Image &image, const Rectangle &bounds);
};

}

#endif // RS_HOGFEATUREEXTRACTOR_H
