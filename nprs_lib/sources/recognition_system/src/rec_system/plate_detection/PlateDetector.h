#ifndef RS_PLATEDETECTOR_H
#define RS_PLATEDETECTOR_H

#include <vector>
#include <common/NprsStd.h>
#include <common/Quad.h>
#include <common/Rectangle.h>

namespace nprs {

class Rectangle;
class ExtremalRegion;
class NumberPlate;
class Quad;

class PlateDetector {
public:
    std::vector<sp<NumberPlate>> detectPlate(const std::vector<ExtremalRegion> &detectedSymbols) const;

private:
    Quad buildBoundingQuad(const Rectangle &rightSymbol, const Rectangle &leftSymbol) const;
};

}

#endif // RS_PLATEDETECTOR_H
