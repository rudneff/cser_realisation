#include <iostream>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterConditional.h>
#include <rec_system/image_processing/region_detection/cser/ERDescriptor.h>
#include <common/Point.h>
#include <common/image/Image.h>

void conditionsTest();
void imageTest();

int main(int argc, char** argv) {
    conditionsTest();
    imageTest();
    std::cin.get();
}

void conditionsTest() {
    std::vector<std::function<bool(const nprs::ERDescriptor&)>> conditions {
        [](const nprs::ERDescriptor& e) { return true; },
        [](const nprs::ERDescriptor& e) { return true; },
        [](const nprs::ERDescriptor& e) { return true; }
    };

    nprs::ERDescriptor er(nprs::Point(10, 10), std::vector<nprs::ICFeature*>());

    for (auto c : conditions) {
        std::cout << c(er) << std::endl;
    }

    std::function<bool(const nprs::ERDescriptor&)> condition = [](const nprs::ERDescriptor& e) { return true; };

    nprs::ERFilterConditional filter(condition);
    bool res = filter.isRegion(er);
    std::cout << res << std::endl;
}

struct tpix {
    tpix()
        : value(65)
    {
        std::cout << "tpix::ctor" << std::endl;
    };

    ~tpix() {
        std::cout << "tpix::dtor" << std::endl;
    }

    int value;
};

void imageTest() {
    nprs::Image<tpix> img(2,2, nprs::ColorInfo(nprs::COLORFORMAT_I255, 1));
}
