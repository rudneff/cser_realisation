#include "ICNumHolesFeature.h"
#include <tuple>

//#define GENUS_DEBUG_OUTPUT

#ifdef GENUS_DEBUG_OUTPUT
#include <iostream>
#include <cstdio>
#endif

using namespace nprs;

static void debugMatrixPrint(const Matrix<int> &m) {
    for (int i = 0; i < m.width(); i++) {
        for (int j = 0; j < m.height(); j++) {
            printf("%s ", m(i, j) ? "*" : " ");
        }
        printf("\n");
    }
}

ICNumHolesFeature::ICNumHolesFeature(Matrix<ERDescriptor*> const* erMap, Image const* image, int channel) 
    : ICFeatureComputer(erMap, image, channel),
      _genus(0)
{
}

ICNumHolesFeature::~ICNumHolesFeature() {
}

void ICNumHolesFeature::init(const Point &p, const ERDescriptor *reg) {
    _genus = 0;
}

void ICNumHolesFeature::increment(const Point &p, const ERDescriptor *reg) {
    auto map = getMap();

    Matrix<int> r(3, 3);
    for (int x = p.x() - 1; x <= p.x() + 1; x++) {
        for (int y = p.y() - 1; y <= p.y() + 1; y++) {
            if (map->isInBounds(x, y)) {
                r(x - p.x() + 1, y - p.y() + 1) = map->getValue(x, y) == reg ? 1 : 0;
            }
        }
    }
   
#ifdef GENUS_DEBUG_OUTPUT
    printf("=========================================\n");
    printf("increment for region: \n");
    debugMatrixPrint(r);
    printf("\n");
    printf("matrix 1: \n");
#endif

    r(1, 1) = 0;
    std::tuple<int, int, int> qc1 = computePatterns(r);

#ifdef GENUS_DEBUG_OUTPUT
    debugMatrixPrint(r);
    printf("c1: %d, c2: %d, cd %d\n", std::get<0>(qc1), std::get<1>(qc1), std::get<2>(qc1));
    printf("------------------------------------\n");
    printf("matrix 2:\n");
#endif

    r(1, 1) = 1;
    std::tuple<int, int, int> qc2 = computePatterns(r);
    
#ifdef GENUS_DEBUG_OUTPUT
    debugMatrixPrint(r);
    printf("c1: %d, c2: %d, cd %d\n", std::get<0>(qc2), std::get<1>(qc2), std::get<2>(qc2));
#endif

    int dc1 = std::get<0>(qc2) - std::get<0>(qc1);
    int dc2 = std::get<1>(qc2) - std::get<1>(qc1);
    int dc3 = std::get<2>(qc2) - std::get<2>(qc1);

    _genus += 0.25 * (dc1 - dc2 + 2 * dc3);

#ifdef GENUS_DEBUG_OUTPUT
    printf("------------------------------------\n");
    printf("dc1: %d, dc2: %d, dcd %d\n", dc1, dc2, dc3);
    std::cout << "genus: " << _genus << std::endl;
#endif
}

void ICNumHolesFeature::combine(const ICFeatureComputer *other, const ERDescriptor *thisReg, const ERDescriptor *otherReg) {
    _genus += (dynamic_cast<const ICNumHolesFeature*>(other))->_genus;
}

float ICNumHolesFeature::getValue() {
    return  1.0f - _genus;
}

std::tuple<int, int, int> ICNumHolesFeature::computePatterns(const Matrix<int> &r) {
    int c1 = 0;
    int c3 = 0;
    int cd = 0;

    for (int x = 0; x < r.width() - 1; x++) {
        for (int y = 0; y < r.height() - 1; y++) {
            int count = 0;

            count += r(x, y) ? 1 : 0;
            count += r(x + 1, y) ? 1 : 0;
            count += r(x, y + 1) ? 1 : 0;
            count += r(x + 1, y + 1) ? 1 : 0;

            if (count == 1) {
                ++c1;
            }
            else if (count == 3) {
                ++c3;
            }
            else if (count == 2) {
                if ((r(x, y) && r(x + 1, y + 1)) || (r(x + 1, y) && r(x, y + 1))) {
                    ++cd;
                }
            }
        }
    }

    return std::make_tuple(c1, c3, cd);
}
