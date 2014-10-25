#ifndef COMMON_MATH_H
#define COMMON_MATH_H

#include <cmath>

namespace nprs {

const double PI = 3.141592653589793;

class Math {
public:
    static const double PI;

    template <typename Scalar>
    static double pow(const Scalar value, double p) {
        return ::pow((double) value, p);
    }

    template <typename Scalar>
    static double sqr(const Scalar &value) {
        return value * value;
    }

    template <typename Scalar>
    static double sqrt(const Scalar &value) {
        return ::sqrt((double) value);
    }

    template <typename Scalar>
    static Scalar min(const Scalar &v1, const Scalar &v2) {
        return v2 < v1 ? v2 : v1;
    }

    template <typename Scalar>
    static Scalar max(const Scalar &v1, const Scalar &v2) {
        return v1 < v2 ? v2 : v1;
    }

    template <typename Scalar>
    static Scalar atan(const Scalar &x) {
        return ::atan((double)x);
    }

    template <typename Scalar>
    static Scalar atan2(const Scalar &x, const Scalar &y) {
        return ::atan2(x, y);
    }

    template <typename Scalar>
    static Scalar abs(const Scalar &x) {
        return x >= 0 ? x : -x;
    }

    template <typename Scalar>
    static Scalar floor(const Scalar &x) {
        return ::floor(x);
    }

    static double cos(double x) {
        return ::cos(x);
    }

    static double sin(double x) {
        return ::sin(x);
    }

    static double rescaleValue(double x, double lowBound, double upBound, double minValue, double maxValue) {
        return (upBound - lowBound) * (x - minValue) / (maxValue - minValue) + lowBound;
    }
};

}

#endif // COMMON_MATH
