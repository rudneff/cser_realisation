#include "CserAlgorithm.h"
#include "rec_system/image_processing/region_detection/cser/ERDescriptor.h"
#include <common/Point.h>
#include <tuple>
#include "rec_system/image_processing/region_detection/cser/features/ICFeature.h"
#include <rec_system/image_processing/region_detection/cser/features/ICAspectRatioFeature.h>
#include <rec_system/image_processing/region_detection/cser/features/ICCompactnessFeature.h>
#include <rec_system/image_processing/region_detection/cser/ERFilter.h>
#include <rec_system/image_processing/region_detection/cser/features/ICHCrossingsFeature.h>
#include <rec_system/image_processing/region_detection/cser/features/ICNumHolesFeature.h>

using namespace nprs;

nprs::CserAlgorithm::CserAlgorithm(const Image &image, 
                                   int channel, 
                                   const std::vector<pERFilter> &filters)
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

    for (auto fclist : _featureComputers) {
        for (auto f : *fclist)
            delete f;
        delete fclist;
    }
}

std::vector<ERDescriptor*> CserAlgorithm::perform() {
    computeHist(_image);
    for (int i = 0; i < 255; i++) {
        increment(i);
    }

    std::vector<ERDescriptor*> filteredRegions = _allRegions;
    for (pERFilter const& filter : _filters) {
        filteredRegions = filter->perform(filteredRegions);
    }

    return filteredRegions;
}

void CserAlgorithm::increment(int threshold) {
    _currentThreshold = threshold;
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

ERDescriptor* CserAlgorithm::newRegion(Point const& p) {
    std::vector<ICFeatureComputer*> *featureComputers = new std::vector<ICFeatureComputer*>(4);

    (*featureComputers)[ERDescriptor::FEATURE_ASPECTRATIO] = new ICAspectRatioFeature(&_erMap, &_image, _channel);
    (*featureComputers)[ERDescriptor::FEATURE_COMPACTNESS] = new ICCompactnessFeature(&_erMap, &_image, _channel);
    (*featureComputers)[ERDescriptor::FEATURE_HCROSSINGS] = new ICHCrossingsFeature(&_erMap, &_image, _channel);
    (*featureComputers)[ERDescriptor::FEATURE_NUMHOLES] = new ICNumHolesFeature(&_erMap, &_image, _channel);

    _featureComputers.push_back(featureComputers);

    ERDescriptor *reg = new ERDescriptor(p, featureComputers, _currentThreshold);

    _allRegions.push_back(reg);
    _erMap(p.x(), p.y()) = reg;

    return reg;
}

ERDescriptor* CserAlgorithm::attachPoint(ERDescriptor *er, const Point &p) {
    ERDescriptor *newReg = er->attachPoint(p, _currentThreshold);
    _allRegions.push_back(newReg);
    _erMap(p.x(), p.y()) = er;

    swapRegions(er, newReg);

    return er;
}

ERDescriptor* CserAlgorithm::combineRegions(const Point &p, ERDescriptor *er1, ERDescriptor *er2) {
    ERDescriptor *newReg = er1->combine(er2, _currentThreshold);
    _allRegions.push_back(newReg);
    
    swapRegions(er1, newReg);

    for (int x = er2->bounds().x(), x1 = er2->bounds().x1(); x < x1; x++) {
        for (int y = er2->bounds().y(), y1 = er2->bounds().y1(); y < y1; y++) {
            if (_erMap(x, y) == er2) {
                _erMap(x, y) = er1;
            }
        }
    }

    return er1;
}

std::set<ERDescriptor*> CserAlgorithm::findNeighbors(const Point &p) {
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

void CserAlgorithm::computeHist(const Image &image) {
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            int intensity = image(x,y,_channel) * 255;
            _hist[intensity].push_back(Point(x,y));
        }
    }
}

void CserAlgorithm::swapRegions(ERDescriptor *r1, ERDescriptor *r2) {
    ERDescriptor temp = *r1;
    *r1 = *r2;
    *r2 = temp;
}
