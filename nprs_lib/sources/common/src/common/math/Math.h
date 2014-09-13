#ifndef COMMON_MATH_H
#define COMMON_MATH_H

#include <cmath>

namespace nprs {

class Math {
public:
    template <typename Scalar>
    static double pow(Scalar value, double p) {
        return ::pow(value, p);
    };

    template <typename Scalar>
    static double sqr(Scalar value) {
        return value * value;
    }
};

}

#endif // COMMON_MATH
