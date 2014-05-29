#include "ExtremalRegion.h"
#include "ERDescriptor.h"

nprs::ExtremalRegion::ExtremalRegion(Rectangle const& bounds)
    : _bounds(bounds)
{}

nprs::ExtremalRegion::ExtremalRegion(ERDescriptor const* erd) 
    : _bounds(erd->bounds())
{
}
