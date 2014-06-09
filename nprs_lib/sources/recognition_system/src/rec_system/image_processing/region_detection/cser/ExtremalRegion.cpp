#include "ExtremalRegion.h"
#include "ERDescriptor.h"

nprs::ExtremalRegion::ExtremalRegion(const Rectangle &bounds)
    : _bounds(bounds)
{}

nprs::ExtremalRegion::ExtremalRegion(const ERDescriptor *erd) 
    : _bounds(erd->bounds())
{
}
