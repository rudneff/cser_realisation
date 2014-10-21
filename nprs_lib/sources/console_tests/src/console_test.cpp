#include <iostream>
#include <rec_system/plate_detection/region_detection/cser/ERDescriptor.h>
#include <common/math/Vector.h>
#include <common/image/Image.h>
#include <common/Point.h>
#include <common/Rectangle.h>
#include <rec_system/plate_detection/PlateDetector.h>
#include <map>

void conditionsTest();
void imageTest();
void arrayTest();
void matrixMoveTest();
void testGroupBy();

int main(int argc, char** argv) {
    //    conditionsTest();
    //    imageTest();
    //    arrayTest();
    //    matrixMoveTest();
    //    std::cin.get();

//    nprs::Point p1(50, 50);
//    nprs::Point p2(20, 20);
//    nprs::Point p3(10, 20);
//    nprs::Point p4(60, 60);
//    nprs::Point p5(10, 5);
//    nprs::Point p6(70, 80);
//
//    std::vector<nprs::Point> points {
//        p1, p2, p3, p4, p5, p6 };
//
//    std::map<nprs::Point, int> m{{ p1, 1 }, { p2, 2 }, { p3, 3 }, { p4, 4 }, { p5, 5 }, { p6, 6 }};
//
//    std::sort(points.begin(), points.end());
//
//    for (auto p : points) {
//        std::cout << "[" << p.x() << ", " << p.y() << "] - " << m[p] << std::endl;
//    }

    testGroupBy();
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

void testGroupBy() {
    using namespace nprs;

    std::vector<Rectangle> plates  {
        Rectangle(21, 28, 5, 15),
        Rectangle(25, 28, 4, 6),
        Rectangle(29, 28, 6, 4),
        Rectangle(33, 28, 5, 4),
        Rectangle(37, 29, 12, 5),
        Rectangle(41, 30, 11, 12),
        Rectangle(58, 38, 15, 9)
    };

    std::map<Rectangle, int> regMap {
        {plates[0], 1},
        {plates[1], 2},
        {plates[2], 3},
        {plates[3], 4},
        {plates[4], 5},
        {plates[5], 6},
        {plates[6], 7}
    };

    PlateDetector pt;
    auto groups = pt.groupBy(
        plates,
        [] (Rectangle const& r1, Rectangle const& r2) { return r1.width() < r2.width(); },
        [] (Rectangle const& r1, Rectangle const& r2) {
            return Math::max(r1.width(), r2.width()) / Math::min(r1.width(), r2.width()) < 1.5;
        });

    auto groupedByWidth = pt.groupBy(
        plates,
        [] (const Rectangle &r1, const Rectangle &r2) { return  r1.width() < r2.width(); },
        [] (const Rectangle &r1, const Rectangle &r2)  {
            return Math::max(r1.width(), r2.width()) / Math::min(r1.width(), r2.width()) < 1.5;
        });

    auto groupedByHeight = pt.groupBy(
        plates,
        [] (const Rectangle &r1, const Rectangle &r2) { return  r1.height() < r2.height(); },
        [] (const Rectangle &r1, const Rectangle &r2)  {
            return Math::max(r1.height(), r2.height()) / Math::min(r1.height(), r2.height()) < 1.5;
        });

    auto groupSize = pt.findIntersections(groupedByWidth, groupedByHeight);
    auto groupsDist = pt.groupByDistance(plates);

    auto groupFinal = pt.groupRegions(plates);

    std::vector<Rectangle> intersection = pt.intersect(groupedByWidth[0], groupedByHeight[0]);

    for (auto group: groups) {
        std::cout << "{";
        for (auto rect: group) {
            std::cout << regMap[rect] << ", ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << "------------------" << std::endl;

    for (auto group: groupedByHeight) {
        std::cout << "{";
        for (auto rect: group) {
            std::cout << regMap[rect] << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << "------------------" << std::endl;

    for (auto group: groupedByWidth) {
        std::cout << "{";
        for (auto rect: group) {
            std::cout << regMap[rect] << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << "------------------" << std::endl;

    for (auto group: groupSize) {
        std::cout << "{";
        for (auto rect: group) {
            std::cout << regMap[rect] << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << "------------------" << std::endl;

    std::cout << "{";
    for (auto rect: intersection) {
        std::cout << regMap[rect] << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << "------------------" << std::endl;

    for (auto group: groupFinal) {
        std::cout << "{";
        for (auto rect: group) {
            std::cout << regMap[rect] << " ";
        }
        std::cout << "}" << std::endl;
    }
}