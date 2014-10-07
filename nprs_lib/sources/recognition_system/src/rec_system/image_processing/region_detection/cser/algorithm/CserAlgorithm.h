#ifndef RECSYSTEM_CSERALGORITHM_H
#define RECSYSTEM_CSERALGORITHM_H

#include <common/image/Image.h>
#include <common/Matrix.h>
#include <memory>
#include <set>

namespace nprs {

class ERDescriptor;
class ERFilter; using pERFilter = std::shared_ptr<ERFilter>;
class Point;
class ICFeatureComputer;

class CserAlgorithm final {
public:
    CserAlgorithm(const Image &image, int channel, const std::vector<pERFilter> &filters);
    CserAlgorithm(const CserAlgorithm&) = delete;
    CserAlgorithm & operator= (const CserAlgorithm &other) = delete;
    ~CserAlgorithm();

    std::vector<ERDescriptor*> perform(); 

private:
    std::vector<ERDescriptor*> _allRegions;
    std::vector<std::vector<ICFeatureComputer*>*> _featureComputers;

    const Image &_image;
    std::vector<pERFilter> const& _filters;
    int _channel;
    std::vector<std::vector<Point>> _hist;
    Matrix<ERDescriptor*> _erMap;

    int _currentThreshold;

    void increment(int threshold);
    void computeHist(const Image &image);

    ERDescriptor* newRegion(Point const& p);
    ERDescriptor* combineRegions(const Point &p, ERDescriptor *er1, ERDescriptor *er2); 
    ERDescriptor* attachPoint(ERDescriptor *er, const Point &p);
    std::set<ERDescriptor*> findNeighbors(const Point &p);
    void swapRegions(ERDescriptor *r1, ERDescriptor *r2);
};

}

#endif // RECSYSTEM_CSERALGORITHM_H
