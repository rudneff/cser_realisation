#include <iostream>
#include <rec_system/plate_detection/region_detection/cser/ERDescriptor.h>
#include <common/math/Vector.h>
#include <common/image/Image.h>

void conditionsTest();
void imageTest();
void arrayTest();
void matrixMoveTest();

int main(int argc, char** argv) {
//    conditionsTest();
//    imageTest();
//    arrayTest();
//    matrixMoveTest();
//    std::cin.get();

    std::vector<int> list = {1, 1};
    auto res = nprs::fold<int>(list, [] (const int &prev, const int &curr) { return (int) prev * curr; });
    auto res2 = nprs::map<int, double>(list, [] (const int &v) { return v + 1; });

    nprs::Vector<int> v(list);

    printf("%d %f\n", res, v.length());

    nprs::Vector<float> v1 = {0, 0};
    nprs::Vector<float> v2 = {4, 3};

    printf("%f", v1.distanceTo(v2));
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
    Image image(100, 100, ColorInfo(ColorFormat::INTENSITY, 1));
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