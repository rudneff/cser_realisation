#ifndef RECSYSTEM_EXTREMALREGION_H
#define RECSYSTEM_EXTREMALREGION_H

#include <common/Rectangle.h>
#include <vector>
#include <common/Point.h>

namespace nprs {

class ERDescriptor;

class ExtremalRegion {
public:
    ExtremalRegion(const Rectangle &bounds, const std::vector<float> &features, int threshold);
    explicit ExtremalRegion(const ERDescriptor *erd);

    const Rectangle & getBounds() const { return _bounds; }
    const std::vector<float> & featureVector() const { return _featureVector; }

private:
    Rectangle _bounds;
    std::vector<float> _featureVector;
    int _threshold;
};

}

#endif // RECSYSTEM_EXTREMALREGION_H
