#include <iostream>
#include <rec_system/plate_detection/region_detection/cser/ERDescriptor.h>
#include <common/math/Vector.h>
#include <common/image/Image.h>
#include <common/Point.h>
#include <map>

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

    nprs::Point p1(50, 50);
    nprs::Point p2(20, 20);
    nprs::Point p3(10, 20);
    nprs::Point p4(60, 60);
    nprs::Point p5(10, 5);
    nprs::Point p6(70, 80);

    std::vector<nprs::Point> points {
        p1, p2, p3, p4, p5, p6 };

    std::map<nprs::Point, int> m{{ p1, 1 }, { p2, 2 }, { p3, 3 }, { p4, 4 }, { p5, 5 }, { p6, 6 }};

    std::sort(points.begin(), points.end());

    for (auto p : points) {
        std::cout << "[" << p.x() << ", " << p.y() << "] - " << m[p] << std::endl;
    }
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