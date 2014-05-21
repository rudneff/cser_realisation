#ifndef REC_SYSTEM_CSERDETECTOR_H
#define REC_SYSTEM_CSERDETECTOR_H

#include <vector>
#include <memory>
#include "common/image/Image.h"

namespace nprs {

class ExtremalRegion; 
class ERFilter; using pERFilter = std::shared_ptr<ERFilter>;

class CSERDetector {
public:
    explicit CSERDetector(const std::vector<pERFilter> &filters);
    ~CSERDetector();

    std::vector<ExtremalRegion> detect(const Image<uchar> &image);

private:
    std::vector<pERFilter> _filters;
};

}

#endif // REC_SYSTEM_CSERDETECTOR_H
