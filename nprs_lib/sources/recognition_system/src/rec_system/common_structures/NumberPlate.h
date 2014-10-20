#ifndef RECSYSTEM_NUMBERPLATE_H
#define RECSYSTEM_NUMBERPLATE_H

#include <common/NprsStd.h>
#include <memory>
#include <common/Rectangle.h>
#include <vector>
#include <common/Quad.h>
#include <common/Line.h>

namespace nprs {

class NumberPlateCharacter;

class NumberPlate {
public:
    NumberPlate(
        const std::vector<sp<NumberPlateCharacter>> &characters, 
        const Quad &bounds, 
        const Line& line);

    NumberPlate(NumberPlate && other);
    NumberPlate & operator= (NumberPlate && other);

    const std::vector<sp<NumberPlateCharacter>> & characters() const { return _characters; }
    const Quad & bounds() const { return _bounds; }
    const Line & line() const { return _line; }

private:
    std::vector<sp<NumberPlateCharacter>> _characters;
    Quad _bounds;
    Line _line;
};

}

#endif
