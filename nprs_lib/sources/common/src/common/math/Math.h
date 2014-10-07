#ifndef COMMON_MATH_H
#define COMMON_MATH_H

#include <cmath>

namespace nprs {

class Math {
public:
    template <typename Scalar>
    static double pow(const Scalar value, double p) {
        return ::pow(value, p);
    };

    template <typename Scalar>
    static double sqr(const Scalar &value) {
        return value * value;
    }

    template <typename Scalar>
    static double sqrt(const Scalar &value) {
        return ::sqrt(value);
    }

    template <typename Scalar>
    static Scalar min(const Scalar &v1, const Scalar &v2) {
        return v2 < v1 ? v2 : v1;
    }

    template <typename Scalar>
    static Scalar max(const Scalar &v1, const Scalar &v2) {
        return v1 < v2 ? v2 : v1;
    }
};

}

#endif // COMMON_MATH
