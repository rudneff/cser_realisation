#include "NumberPlate.h"

#include <iostream>

using namespace nprs;

NumberPlate::NumberPlate(const std::vector<pNumberPlateCharacter> &characters, const Rectangle &bounds)
    : _bounds(bounds), _characters(characters)
{
}

NumberPlate::NumberPlate(NumberPlate && other)
    : _bounds(other._bounds), _characters(std::move(other._characters))
{
    std::cout << "NumberPlate move ctor" << std::endl;
}

NumberPlate& NumberPlate::operator=(NumberPlate && other) {
    std::cout << "NumberPlate move =" << std::endl;
    if (this != &other) {
        _bounds = other._bounds;
        _characters = std::move(other.characters());
    }
    return *this;
}
