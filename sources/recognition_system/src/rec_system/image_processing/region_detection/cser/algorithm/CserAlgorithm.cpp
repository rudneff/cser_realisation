#include "CserAlgorithm.h"
#include "rec_system/image_processing/region_detection/cser/ERDescriptor.h"
#include <common/Point.h>
#include <tuple>

using namespace nprs;

nprs::CserAlgorithm::CserAlgorithm(Image<uchar> const& image, 
                                   int channel, 
                                   std::vector<pERFilter> const& filters)
     : _image(image), 
       _erMap(image.width(), image.height()), 
       _filters(filters), 
       _hist(255)
{
}

nprs::CserAlgorithm::~CserAlgorithm() {
    for (auto r : _allRegions) {
        delete r;
    }
}

std::vector<nprs::ERDescriptor*> nprs::CserAlgorithm::perform() {
    for (int i = 0; i < 255; i++) {
        increment(i);
    }

    return {};
}

void nprs::CserAlgorithm::increment(int threshold) {
    for (Point p : _hist[threshold]) {
        auto neighbors = findNeighbors(p);
        if (neighbors.size() == 0) {
            ERDescriptor *reg = newRegion(p);
        } else if (neighbors.size() == 1) {
            ERDescriptor *reg = attachPoint(*(neighbors.begin()), p);
        } else if (neighbors.size() > 1) {
            ERDescriptor *reg = attachPoint(*(neighbors.begin()), p);
            for (ERDescriptor *neighbor: neighbors) {
                reg = mergeRegions(reg, neighbor);
            }
        }
    }
}

ERDescriptor* nprs::CserAlgorithm::newRegion(Point const& p) {
    ERDescriptor *reg = new ERDescriptor(p);
    _allRegions.push_back(reg);
    _erMap(p.x(), p.y()) = reg;
    return reg;
}

ERDescriptor* CserAlgorithm::mergeRegions(const ERDescriptor *er1, const ERDescriptor *er2) {
    float area = er1->area() + er2->area();
    float perimeter = er1->perimeter() + er2->perimeter();
}

std::set<ERDescriptor*> CserAlgorithm::findNeighbors(Point const& p) {
    ERDescriptor* pd = _erMap(p.x(), p.y());
    std::set<ERDescriptor*> nbs;

    for (Point n : { Point(-1,0), Point(1,0), Point(0,1), Point(0,-1) }) {
        Point q = n + p;
        ERDescriptor *nd = _erMap(q.x(), q.y());
    }
}

ERDescriptor* CserAlgorithm::attachPoint(const ERDescriptor *er, Point const& p) {
    
}

void CserAlgorithm::computeHist(Image<uchar> const& image) {
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            uchar intensity = image(x,y,_channel);
            _hist[intensity].push_back(Point(x,y));
        }
    }
}

std::vector<int> CserAlgorithm::mergeCrossings(const std::vector<int> &c1, const std::vector<int> &c2) {
    return std::vector<int>();
}
