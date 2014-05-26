#ifndef RECSYSTEM_CSERALGORITHM_H
#define RECSYSTEM_CSERALGORITHM_H

#include <common/image/Image.h>
#include <common/Matrix.h>
#include <memory>
#include <set>

namespace nprs {

template <typename T> using pVector = std::shared_ptr<std::vector<T>>;
template <typename T> using pImage = std::shared_ptr<Image<T>>;
class ERDescriptor;
class ERFilter; using pERFilter = std::shared_ptr<ERFilter>;
class Point;

class CserAlgorithm {
public:
    CserAlgorithm(Image<uchar> const& image, int channel, const std::vector<pERFilter> &filters);
    ~CserAlgorithm();

    std::vector<ERDescriptor*> perform();

private:
    std::vector<ERDescriptor*> _allRegions;
    std::vector<ERDescriptor*> _filteredRegions;
    Image<uchar> const& _image;
    std::vector<pERFilter> const& _filters;
    int _channel;
    std::vector<std::vector<Point>> _hist;

    Matrix<ERDescriptor*> _erMap;
    std::vector<ERDescriptor*> _ers;

    void increment(int threshold);
    void computeHist(Image<uchar> const& image);
    ERDescriptor* newRegion(Point const& p);
    ERDescriptor* mergeRegions(const ERDescriptor *er1, const ERDescriptor *er2); 
    ERDescriptor* attachPoint(const ERDescriptor *er, const Point &p);
    std::set<ERDescriptor*> findNeighbors(Point const& p);
    
    std::vector<int> mergeCrossings(const std::vector<int> &er1, const std::vector<int> &er2);
};

}

#endif // RECSYSTEM_CSERALGORITHM_H
