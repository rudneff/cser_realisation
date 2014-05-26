#ifndef RECSYSTEM_ERDESCRIPTOR_H
#define RECSYSTEM_ERDESCRIPTOR_H

#include <vector>
#include <common/Rectangle.h>
#include <common/Matrix.h>
#include <memory>

namespace nprs {

class Point;
class ERDescriptor; using pERDescriptor = std::shared_ptr<ERDescriptor>;

class ERDescriptor {
public:
    explicit ERDescriptor(const Point& p);

    ERDescriptor(Rectangle const& bounds, 
                 float area, 
                 float perimeter, 
                 float eulerNumber, 
                 const std::vector<int> &crossings);

    Rectangle const& bounds() const { return _bounds; }
    float area() const { return _area; }
    float perimeter() const { return _perimeter; }
    float eulerNumber() const { return _eulerNumber; }
    std::vector<int> const& crossings() const { return _crossings; }

private:
    Rectangle _bounds;
    float _area;
    float _perimeter;
    float _eulerNumber;
    std::vector<int> _crossings;

    ERDescriptor *_next;
    ERDescriptor *_prev;
};

}

#endif // RECSYSTEM_ERDESCRIPTOR_H
