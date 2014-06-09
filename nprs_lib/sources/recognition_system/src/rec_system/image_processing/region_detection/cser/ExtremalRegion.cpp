#include "ExtremalRegion.h"
#include "ERDescriptor.h"

nprs::ExtremalRegion::ExtremalRegion(const Rectangle &bounds, const std::vector<float> &features, int threshold)
    : _bounds(bounds), _featureVector(features), _threshold(threshold)
{}

nprs::ExtremalRegion::ExtremalRegion(const ERDescriptor *erd) 
    : _bounds(erd->bounds()), _featureVector(erd->featureVector()), _threshold(erd->threshold())
{}
