#ifndef RECSYSTEM_EXTREMALREGION_H
#define RECSYSTEM_EXTREMALREGION_H

#include <common/Rectangle.h>
#include <vector>

namespace nprs {

class ERDescriptor;
class Point;

class ExtremalRegion {
public:
    ExtremalRegion(const Rectangle &bounds, const std::vector<float> &features, int threshold);
    explicit ExtremalRegion(const ERDescriptor *erd);

    const Rectangle & bounds() const { return _bounds; }
    const std::vector<float> & lightFeatures() const { return _lightFeatures; }
    int threshold() const { return _threshold; }

private:
    Rectangle _bounds;
    std::vector<float> _lightFeatures;
    int _threshold;
};

}

#endif // RECSYSTEM_EXTREMALREGION_H
