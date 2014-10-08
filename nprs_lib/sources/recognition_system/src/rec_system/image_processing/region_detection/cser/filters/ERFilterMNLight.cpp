#include "ERFilterMNLight.h"
#include <rec_system/image_processing/region_detection/cser/ERDescriptor.h>
#include <stack>
#include <iostream>

namespace nprs {

static bool isLocalMaximum(const ERDescriptor *reg, const DecisionMaker &dm);

ERFilterMNLight::ERFilterMNLight(sp<DecisionMaker> const& regressor)
: _regressor(regressor)
{
}

ERFilterMNLight::~ERFilterMNLight() {
}

std::vector<ERDescriptor *> ERFilterMNLight::perform(const std::vector<ERDescriptor *> &regions) {
    std::cout << regions.size() << std::endl;

    std::vector<ERDescriptor *> result;

    for (ERDescriptor * descriptor : regions) {
        double val = (*_regressor)(descriptor->featureVector());
        if (val > 0.3) {
            result.push_back(descriptor);
        }
    }

//    const ERDescriptor *root = regions[regions.size() - 1];
//
//    std::stack<ERDescriptor const*> uncheckedRoots;
//    uncheckedRoots.push(root);
//
//    while (!uncheckedRoots.empty()) {
//        const ERDescriptor *reg = uncheckedRoots.top();
//        uncheckedRoots.pop();
//
//        std::cout << "popped region " << reg << std::endl;
//        while (reg->parent1() != nullptr) {
//            std::cout << reg->featureVector()[0] << " " << reg->featureVector()[1] << std::endl;
//            if (isLocalMaximum(reg, *_regressor)) {
//                result.push_back(const_cast<ERDescriptor*>(reg));
//            }
//            if (reg->parent2() != nullptr) {
//                uncheckedRoots.push(reg->parent2());
//                std::cout << "pushed region " << reg->parent2() << std::endl;
//            }
//
//            reg = reg->parent1();
//        }
//    }

    return result;
}

static bool isLocalMaximum(const ERDescriptor *reg, const DecisionMaker &dm) {
    double childValue = !reg->child() ? -1 : dm(reg->child()->featureVector());
    double parent1Value = !reg->parent1() ? -1 : dm(reg->parent1()->featureVector());
    double parent2Value = !reg->parent2() ? -1 : dm(reg->parent2()->featureVector());
    double currValue = dm(reg->featureVector());

    return (currValue > childValue && currValue > parent1Value) || (currValue > childValue && currValue > parent2Value);
}

}
