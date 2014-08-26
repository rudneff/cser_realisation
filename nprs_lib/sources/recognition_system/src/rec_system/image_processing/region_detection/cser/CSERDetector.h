#ifndef REC_SYSTEM_CSERDETECTOR_H
#define REC_SYSTEM_CSERDETECTOR_H

#include <common/NprsStd.h>
#include <vector>
#include <memory>
#include "common/image/Image.h"
#include "common/Matrix.h"

namespace nprs {

class ExtremalRegion;
class ERFilter;
class Point;

class CSERDetector {
public:
    explicit CSERDetector(const std::vector<sp<ERFilter>> &filters);
    ~CSERDetector();
    
    std::vector<ExtremalRegion> detect(Image const& image);

private:
    std::vector<sp<ERFilter>> _filters;
};

}

#endif // REC_SYSTEM_CSERDETECTOR_H
