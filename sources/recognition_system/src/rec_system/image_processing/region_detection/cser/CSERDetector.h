#ifndef REC_SYSTEM_CSERDETECTOR_H
#define REC_SYSTEM_CSERDETECTOR_H

#include <vector>
#include <memory>
#include "common/image/Image.h"
#include "common/Matrix.h"

namespace nprs {

class ExtremalRegion;
class ERFilter; using pERFilter = std::shared_ptr<ERFilter>;
class ERDescriptor; using pERDescirptor = std::shared_ptr<ERDescriptor>;
class Point;

class CSERDetector {
public:
    explicit CSERDetector(const std::vector<pERFilter> &filters);
    ~CSERDetector();

    std::vector<ExtremalRegion> detect(const Image<uchar> &image);

private:
    std::vector<pERFilter> _filters;

    ERDescriptor newRegion(const Point& p);
    ERDescriptor addPointToRegion(const Point &p);
    ERDescriptor mergeRegions(const ERDescriptor& r1, const ERDescriptor &r2);
};

}

#endif // REC_SYSTEM_CSERDETECTOR_H
