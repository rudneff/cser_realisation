#include "CserAlgorithm.h"
#include "rec_system/image_processing/region_detection/cser/ERDescriptor.h"
#include <common/Point.h>
#include <tuple>
#include "rec_system/image_processing/region_detection/cser/features/ICFeature.h"
#include <rec_system/image_processing/region_detection/cser/features/ICAspectRatioFeature.h>
#include <rec_system/image_processing/region_detection/cser/features/ICCompactnessFeature.h>

using namespace nprs;

nprs::CserAlgorithm::CserAlgorithm(Image const& image, 
                                   int channel, 
                                   std::vector<pERFilter> const& filters)
     : _image(image), 
       _erMap(image.width(), image.height()), 
       _filters(filters), 
       _hist(256),
       _channel(channel)
{
    memset(_erMap.data(), 0, _erMap.width() * _erMap.height() * sizeof(ERDescriptor*));
}

nprs::CserAlgorithm::~CserAlgorithm() {
    for (ERDescriptor *r : _allRegions)
        delete r;

    for (ICFeature *f : _features)
        delete f;
}

std::vector<nprs::ERDescriptor*> nprs::CserAlgorithm::perform() {
    computeHist(_image);
    for (int i = 0; i < 255; i++) {
        increment(i);
    }
    return _allRegions;
}

void nprs::CserAlgorithm::increment(int threshold) {
    for (Point p : _hist[threshold]) {
        auto neighbors = findNeighbors(p);
        if (neighbors.size() == 0) {
            newRegion(p);
        } else if (neighbors.size() == 1) {
            attachPoint(*(neighbors.begin()), p);
        } else if (neighbors.size() > 1) {
            ERDescriptor *reg = attachPoint(*(neighbors.begin()), p);
            neighbors.erase(neighbors.begin());
            for (ERDescriptor *neighbor: neighbors) {
                if (neighbor != reg)
                    reg = combineRegions(p, reg, neighbor);
            }
        }
    }
}

ERDescriptor* nprs::CserAlgorithm::newRegion(Point const& p) {
    std::vector<ICFeature*> featureComputers(2);
    featureComputers[ERDescriptor::FEATURE_ASPECTRATIO] = new ICAspectRatioFeature(&_erMap, &_image, _channel);
    featureComputers[ERDescriptor::FEATURE_COMPACTNESS] = new ICCompactnessFeature(&_erMap, &_image, _channel);

    ERDescriptor *reg = new ERDescriptor(p, featureComputers);

    _allRegions.push_back(reg);
    _erMap(p.x(), p.y()) = reg;
    return reg;
}

ERDescriptor* CserAlgorithm::attachPoint(ERDescriptor *er, Point const& p) {
    ERDescriptor *newReg = er->attachPoint(p);
    _allRegions.push_back(newReg);
    _erMap(p.x(), p.y()) = newReg;
    const Rectangle &bounds = newReg->bounds();

    for (Point p : *(newReg->points())) {
        _erMap(p.x(), p.y()) = newReg;
    }

    return newReg;
}

ERDescriptor* CserAlgorithm::combineRegions(const Point &p, ERDescriptor *er1, ERDescriptor *er2) {
    ERDescriptor *newReg = er1->combine(er2);
    _allRegions.push_back(newReg);

    for (Point p : *(newReg->points())) {
        _erMap(p.x(), p.y()) = newReg;
    }

    return newReg;
}

std::set<ERDescriptor*> CserAlgorithm::findNeighbors(Point const& p) {
    ERDescriptor* pd = _erMap(p.x(), p.y());
    std::set<ERDescriptor*> nbs;

    for (Point n : { Point(-1,0), Point(1,0), Point(0,1), Point(0,-1) }) {
        Point q = n + p;
        if (_erMap.isInBounds(q.x(), q.y()) && _erMap(q.x(), q.y())) {
            nbs.insert(_erMap(q.x(), q.y()));
        }
    }

    return nbs;
}

void CserAlgorithm::computeHist(Image const& image) {
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            int intensity = image(x,y,_channel) * 255;
            _hist[intensity].push_back(Point(x,y));
        }
    }
}
