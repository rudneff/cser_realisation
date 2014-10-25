#ifndef COMMON_VEC_H
#define COMMON_VEC_H

#include <array>
#include <common/math/Math.h>
#include <algorithm>

namespace nprs {

template <int DimCount, typename Scalar = double>
class Vec {
public:
    Vec(std::array<Scalar, DimCount> const& coords)
        : _coords(coords)
    {}

    Vec(std::array<Scalar, DimCount> && coords)
        : _coords(coords)
    {}

    Scalar& operator[] (int dim) {
        return _coords[dim];
    }

    const Scalar& operator[] (int dim) const {
        return _coords[dim];
    }

    template <typename O>
    double distanceTo(Vec<DimCount, O> const& other) const {
        Scalar sqr = 0.0;
        for (int i = 0; i < DimCount; i++) {

        }
    }

    Scalar max(int *outDim = 0) const {
        Scalar max = _coords[0];
        for (int dim = 1; dim < DimCount; dim++) {
            if (_coords[dim] > max) {
                max = _coords[dim];
                outDim ? *outDim = dim : 0;
            }
        }

        return max;
    }

    Scalar min(int *outDim = 0) const {
        Scalar min = _coords[0];
        for (int dim = 1; dim < DimCount; dim++) {
            if (_coords[dim] < min) {
                min = _coords[dim];
                outDim ? *outDim = dim : 0;
            }
        }

        return min;
    }

    double length() const {
        double sqrSum = 0.0;
        for (int i = 0; i < DimCount; i++) {
            sqrSum += _coords[i] * _coords[i];
        }
        return Math::sqrt(sqrSum);
    }

    Vec<DimCount, Scalar> normalize() const {
        std::array<Scalar, DimCount> coords;
        double len = length();
        for (int i = 0; i < DimCount; i++) {
            coords[i] = _coords[i] / len;
        }

        return std::move(coords);
    }

    template <typename O>
    Vec<DimCount, Scalar> operator+ (Vec<DimCount, O> const& other) {
        std::array<Scalar, DimCount> coords;

        for (int i = 0; i < DimCount; i++) {
            coords[i] = _coords[i] + other._coords[i];
        }

        return std::move(coords);
    }

    template <typename O>
    Vec<DimCount, Scalar> operator- (Vec<DimCount, O> const& other) {
        std::array<Scalar, DimCount> coords;
        for (int i = 0; i < DimCount; i++) {
            coords[i] = _coords[i] - other._coords[i];
        }

        return std::move(coords);
    }

    Vec<DimCount, Scalar> operator* (double k) const {
        std::array<Scalar, DimCount> coords;
        for (int i = 0; i < DimCount; i++) {
            coords[i] = _coords[i] * k;
        }

        return std::move(coords);
    }

    Vec<DimCount, Scalar> operator/ (double k) const {
        std::array<Scalar, DimCount> coords;
        for (int i = 0; i < DimCount; i++) {
            coords[i] = _coords[i] / k;
        }

        return std::move(coords);
    }

private:
    std::array<Scalar, DimCount> _coords;
};

}

#endif // COMMON_VEC_H
