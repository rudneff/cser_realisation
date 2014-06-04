#include "ICHCrossingsFeature.h"
#include <algorithm>

using namespace nprs;

ICHCrossingsFeature::ICHCrossingsFeature(const Matrix<ERDescriptor*> *erMap, const Image *image, int channel)
    : ICFeature(erMap, image, channel), _ytop(0), _ybottom(0)
{
}

void ICHCrossingsFeature::combine(const ICFeature *other, const ERDescriptor *thisReg, const ERDescriptor *otherReg) {
    auto that = static_cast<const ICHCrossingsFeature*>(other);

    int ytop = fmin(this->_ytop, that->_ytop);
    int ybottom = fmax(this->_ybottom, that->_ybottom);
    
    std::deque<int> nc;
    nc.resize(ybottom - ytop + 1);

    for (int& n : nc) {
        n = 0;
    }

    for (int y = ytop; y <= ybottom; y++) {
        if (y >= this->_ytop && y <= this->_ybottom) {
            nc[y - ytop] += this->_numCrossings[y - this->_ytop];
        }
        if (y >= that->_ytop && y <= that->_ybottom) {
            nc[y - ytop] += that->_numCrossings[y - that->_ytop];
        }
    }

    _ytop = ytop;
    _ybottom = ybottom;
    _numCrossings = nc;
}

void ICHCrossingsFeature::increment(const Point &p, const ERDescriptor *reg) {
    auto map = getMap();
    auto image = getImage();

    int transitions = 0;
    transitions += (*map)(p.x() - 1, p.y()) == reg ? -1 : 1;
    transitions += map->isInBounds(p.x() + 1, p.y()) && (*map)(p.x() + 1, p.y()) == reg ? -1 : 1;

    if (p.y() < _ytop) {
        _ytop = p.y();
        _numCrossings.push_front(transitions);
    }
    else if (p.y() > _ybottom) {
        _ybottom = p.y();
        _numCrossings.push_back(transitions);
    }
    else {
        _numCrossings[p.y() - _ytop] += transitions;
    }
}

void ICHCrossingsFeature::init(const Point &p, const ERDescriptor *reg) {
    _ytop = _ybottom = p.y();
    _numCrossings.push_back(2);
}

float ICHCrossingsFeature::getValue() {
    float res = _numCrossings[0];

    if (_numCrossings.size() > 1) {
        float m[3];
        m[0] = _numCrossings[_numCrossings.size() * 0.16];
        m[1] = _numCrossings[_numCrossings.size() * 0.50];
        m[2] = _numCrossings[_numCrossings.size() * 0.83];
        std::sort(m, m + 3);
        res = m[1];
    }

    return res;
}
