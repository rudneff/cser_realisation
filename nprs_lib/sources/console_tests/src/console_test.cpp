#include <iostream>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterConditional.h>
#include <rec_system/image_processing/region_detection/cser/ERDescriptor.h>
#include <common/Point.h>
#include <common/image/Image.h>

void conditionsTest();
void imageTest();
void arrayTest();
void matrixMoveTest();

int main(int argc, char** argv) {
    conditionsTest();
    imageTest();
    arrayTest();
    matrixMoveTest();
    std::cin.get();
}

void conditionsTest() {
}

struct tpix {
    tpix(int value) : value(value) {}

    tpix()
        : value(65)
    {
        std::cout << "tpix::ctor" << std::endl;
    };

    tpix(const tpix& other) 
        : value(other.value)
    {
        std::cout << "tpix::cctor" << std::endl;
    }

    ~tpix() {
        std::cout << "tpix::dtor" << std::endl;
    }

    int value;
};

void imageTest() {
    using namespace nprs;
    Image image(100, 100, ColorInfo(ColorFormat::INT, 1));
}

nprs::Matrix<tpix> newMatrix() {
    nprs::Matrix<tpix> m(2,2);
    m(1,1) = -102;
    return m;
}

void matrixMoveTest() {
    std::cout << "matrix move: " << std::endl;
    nprs::Matrix<tpix> m = newMatrix();
    std::cout << m(1,1).value << std::endl;
    std::cout << "------" << std::endl;
}

void arrayTest() {
}