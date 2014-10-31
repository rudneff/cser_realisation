#include "NumberPlate.h"

#include <iostream>

using namespace nprs;

NumberPlate::NumberPlate(
    const std::vector<sp<NumberPlateCharacter>> &characters, 
    const Quad &bounds,
    const Line &line,
    Rectangle rect)
    : _bounds(bounds), 
      _characters(characters),
      _line(line),
      _boundingRect(rect)
{
}

NumberPlate::NumberPlate(NumberPlate && other)
    : _bounds(other._bounds), 
      _characters(std::move(other._characters)),
      _line(other._line)
{
}

NumberPlate& NumberPlate::operator=(NumberPlate && other) {
    if (this != &other) {
        _bounds = other._bounds;
        _characters = std::move(other.characters());
        _line = other._line;
    }
    return *this;
}
