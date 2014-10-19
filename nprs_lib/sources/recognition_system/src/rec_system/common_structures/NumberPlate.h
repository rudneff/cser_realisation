#ifndef RECSYSTEM_NUMBERPLATE_H
#define RECSYSTEM_NUMBERPLATE_H

#include <common/NprsStd.h>
#include <memory>
#include <common/Rectangle.h>
#include <vector>
#include <common/Quad.h>

namespace nprs {

class NumberPlateCharacter;

class NumberPlate {
public:
    NumberPlate(const std::vector<sp<NumberPlateCharacter>> &characters, const Quad &bounds);

    NumberPlate(NumberPlate && other);
    NumberPlate & operator= (NumberPlate && other);

    std::vector<sp<NumberPlateCharacter>> characters() const { return _characters; }
    Quad bounds() const { return _bounds; }

private:
    std::vector<sp<NumberPlateCharacter>> _characters;
    Quad _bounds;
};

}

#endif
