#ifndef REC_SYSTEM_CSERDETECTOR_H
#define REC_SYSTEM_CSERDETECTOR_H

#include <vector>
#include <memory>
#include "common/image/Image.h"
#include "common/Matrix.h"

namespace nprs {

class ExtremalRegion;
class ERFilter; using pERFilter = std::shared_ptr<ERFilter>;
class ERDescriptor; using pERDescriptor = std::shared_ptr<ERDescriptor>;
class Point;

class CSERDetector {
public:
    explicit CSERDetector(const std::vector<pERFilter> &filters);
    ~CSERDetector();

    std::vector<ExtremalRegion> detect(Image const& image);

private:
    std::vector<pERFilter> _filters;
};

}

#endif // REC_SYSTEM_CSERDETECTOR_H
