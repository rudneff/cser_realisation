#ifndef RECSYSTEM_ERDESCRIPTOR_H
#define RECSYSTEM_ERDESCRIPTOR_H

#include <vector>
#include <common/Rectangle.h>
#include <common/Matrix.h>

namespace nprs {

class Point;

class ERDescriptor {
public:
    explicit ERDescriptor(const Point& p);

    ERDescriptor(Rectangle bounds, 
                 float area, 
                 float perimeter, 
                 float eulerNumber, 
                 const std::vector<int> &crossings);

    Rectangle bounds() { return _bounds; }
    float area() { return _area; }
    float perimeter() { return _perimeter; }
    float eulerNumber() { return _eulerNumber; }
    std::vector<int> crossings() { return _crossings; }

private:
    Rectangle _bounds;
    float _area;
    float _perimeter;
    float _eulerNumber;
    std::vector<int> _crossings;
};

}

#endif // RECSYSTEM_ERDESCRIPTOR_H
