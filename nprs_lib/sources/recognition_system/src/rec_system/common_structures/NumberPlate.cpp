#include "NumberPlate.h"

#include <iostream>

using namespace nprs;

NumberPlate::NumberPlate(const std::vector<sp<NumberPlateCharacter>> &characters, const Quad &bounds)
    : _bounds(bounds), _characters(characters)
{
}

NumberPlate::NumberPlate(NumberPlate && other)
    : _bounds(other._bounds), _characters(std::move(other._characters))
{
}

NumberPlate& NumberPlate::operator=(NumberPlate && other) {
    if (this != &other) {
        _bounds = other._bounds;
        _characters = std::move(other.characters());
    }
    return *this;
}
