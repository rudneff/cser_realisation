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
class ICFeature;

class CserAlgorithm {
public:
    CserAlgorithm(Image const& image, int channel, const std::vector<pERFilter> &filters);
    CserAlgorithm(const CserAlgorithm&) = delete;
    CserAlgorithm& operator= (const CserAlgorithm& other) = delete;
    ~CserAlgorithm();

    std::vector<ERDescriptor*> perform();

private:
    std::vector<ERDescriptor*> _allRegions;
    std::vector<ERDescriptor*> _filteredRegions;
    std::vector<ICFeature*> _features;

    Image const& _image;
    std::vector<pERFilter> const& _filters;
    int _channel;
    std::vector<std::vector<Point>> _hist;
    Matrix<ERDescriptor*> _erMap;

    void increment(int threshold);
    void computeHist(Image const& image);

    ERDescriptor* newRegion(Point const& p);
    ERDescriptor* combineRegions(const Point &p, ERDescriptor *er1, ERDescriptor *er2); 
    ERDescriptor* attachPoint(ERDescriptor *er, const Point &p);
    std::set<ERDescriptor*> findNeighbors(Point const& p);
};

}

#endif // RECSYSTEM_CSERALGORITHM_H
