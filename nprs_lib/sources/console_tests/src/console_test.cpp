#include <iostream>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterConditional.h>
#include <rec_system/image_processing/region_detection/cser/ERDescriptor.h>
#include <common/Point.h>
#include <common/image/Image.h>

void conditionsTest();
void imageTest();
void arrayTest();

int main(int argc, char** argv) {
    conditionsTest();
    imageTest();
    arrayTest();
    std::cin.get();
}

void conditionsTest() {
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
    using namespace nprs;
    Image image(100, 100, ColorInfo(ColorFormat::INT, 1));
}

void arrayTest() {
}