#include "ERDescriptor.h"
#include <common/Point.h>

nprs::ERDescriptor::ERDescriptor(const Point &p)
    : _bounds(p.x(), p.y(), 1, 1),
      _area(1),
      _perimeter(1),
      _eulerNumber(0)
{
    
}

nprs::ERDescriptor::ERDescriptor(Rectangle bounds, 
                                 float area, 
                                 float perimeter, 
                                 float eulerNumber, 
                                 std::vector<int> const& crossings)

    : _bounds(bounds), 
      _area(area), 
      _perimeter(perimeter), 
      _eulerNumber(eulerNumber), 
      _crossings(crossings)
{
    
}
