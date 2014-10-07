#include "ExtremalRegion.h"
#include "ERDescriptor.h"
#include <common/Point.h>

nprs::ExtremalRegion::ExtremalRegion(const Rectangle &bounds, const std::vector<float> &features, int threshold)
    : _bounds(bounds), _lightFeatures(features), _threshold(threshold)
{}

nprs::ExtremalRegion::ExtremalRegion(const ERDescriptor *erd) 
    : _bounds(erd->bounds()), _lightFeatures(erd->featureVector()), _threshold(erd->threshold())
{}
