#include <iostream>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterConditional.h>
#include <rec_system/image_processing/region_detection/cser/ERDescriptor.h>
#include <common/Point.h>

void conditionsTest();

int main(int argc, char** argv) {
    conditionsTest();
    std::cin.get();
}

void conditionsTest() {
    std::vector<std::function<bool(const nprs::ERDescriptor&)>> conditions{
        [](const nprs::ERDescriptor&) { return true; },
        [](const nprs::ERDescriptor&) { return true; },
        [](const nprs::ERDescriptor&) { return true; }
    };

    nprs::ERDescriptor er(nprs::Point(10, 10));

    for (auto c : conditions) {
        std::cout << c(er) << std::endl;
    }

    nprs::ERFilterConditional filter(conditions);
    bool res = filter.isRegion(er);
    std::cout << res << std::endl;
}
