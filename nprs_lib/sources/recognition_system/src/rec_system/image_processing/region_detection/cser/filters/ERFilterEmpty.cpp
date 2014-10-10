#include "ERFilterEmpty.h"

using namespace nprs;

std::vector<ERDescriptor*> ERFilterEmpty::perform(const std::vector<ERDescriptor*> &regions) {
    return regions;
}
