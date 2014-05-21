#ifndef RECSYSTEM_NUMBERPLATE_H
#define RECSYSTEM_NUMBERPLATE_H

#include <memory>
#include <common/Rectangle.h>
#include <vector>

namespace nprs {

class NumberPlateCharacter; using pNumberPlateCharacter = std::shared_ptr<NumberPlateCharacter>;

class NumberPlate {
public:
    NumberPlate(const std::vector<pNumberPlateCharacter> &characters, Rectangle bounds)
        : _characters(characters), _bounds(bounds)
    {}

    std::vector<pNumberPlateCharacter> characters() const { return _characters; }
    Rectangle bounds() const { return _bounds; }

private:
    std::vector<pNumberPlateCharacter> _characters;
    Rectangle _bounds;
};

}

#endif
