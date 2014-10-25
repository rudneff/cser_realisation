#include "ERFilterMNLight.h"
#include <rec_system/plate_detection/region_detection/cser/ERDescriptor.h>
#include <stack>
#include <iostream>
#include <common/image/Image.h>
#include <map>

namespace nprs {

const double ERFilterMNLight::THRESHOLD = 0.3;

static bool isLocalMaximum(const ERDescriptor *reg, const std::map<const ERDescriptor*, float> &dm);

ERFilterMNLight::ERFilterMNLight(sp<DecisionMaker> const& regressor)
: _regressor(regressor)
{
}

ERFilterMNLight::~ERFilterMNLight() {
}

std::vector<ERDescriptor *> ERFilterMNLight::perform(const std::vector<ERDescriptor *> &regions, Image const &image) {
    std::cout << regions.size() << std::endl;

    std::vector<ERDescriptor *> result;

//    for (ERDescriptor * descriptor : regions) {
//        double val = (*_regressor)(descriptor->featureVector());
//
//        if (val > 0.5) {
//            result.push_back(descriptor);
//
//            auto fv = descriptor->featureVector();
//            std::cout << fv[0] << " " << " " << fv[1] << " " << fv[2] << " " <<  fv[3] << " " << val << std::endl;
//        }
//    }

    std::map<const ERDescriptor*, float> responseMap;
    for (ERDescriptor * er: regions) {
        responseMap[er] = (*_regressor)(er->featureVector());
    }

    const ERDescriptor *root = regions[regions.size() - 1];

    std::stack<ERDescriptor const*> uncheckedRoots;
    uncheckedRoots.push(root);

    while (!uncheckedRoots.empty()) {
        const ERDescriptor *reg = uncheckedRoots.top();
        uncheckedRoots.pop();

        while (reg->parent1() != nullptr) {
            if (isLocalMaximum(reg, responseMap)) {
                result.push_back(const_cast<ERDescriptor *>(reg));
            }
            if (reg->parent2() != nullptr) {
                uncheckedRoots.push(reg->parent2());
            }
            reg = reg->parent1();
        }
    }

    std::cout << result.size() << std::endl;

    return result;
}

static bool isLocalMaximum(const ERDescriptor *reg, const std::map<const ERDescriptor*, float> &dm) {
    static const double eps = 0.01;

    if (reg->bounds().area() < 15)
        return false;

    double currValue = dm.at(reg);
    if (currValue < ERFilterMNLight::THRESHOLD)
        return false;

    double childValue = !reg->child() ? -1 : dm.at(reg->child());
    double parent1Value = !reg->parent1() ? -1 : dm.at(reg->parent1());
    double parent2Value = !reg->parent2() ? -1 : dm.at(reg->parent2());

    return (currValue - childValue > eps && currValue - parent1Value > eps) ||
           (currValue - childValue > eps && currValue - parent2Value > eps);
}

}
