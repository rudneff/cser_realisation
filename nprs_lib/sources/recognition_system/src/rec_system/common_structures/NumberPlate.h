#ifndef RECSYSTEM_NUMBERPLATE_H
#define RECSYSTEM_NUMBERPLATE_H

#include <common/NprsStd.h>
#include <memory>
#include <common/Rectangle.h>
#include <vector>

namespace nprs {

class NumberPlateCharacter;

class NumberPlate {
public:
    NumberPlate(const std::vector<sp<NumberPlateCharacter>> &characters, const Rectangle &bounds);

    NumberPlate(NumberPlate && other);
    NumberPlate & operator= (NumberPlate && other);

    std::vector<sp<NumberPlateCharacter>> characters() const { return _characters; }
    Rectangle bounds() const { return _bounds; }

private:
    std::vector<sp<NumberPlateCharacter>> _characters;
    Rectangle _bounds;
};

}

#endif
