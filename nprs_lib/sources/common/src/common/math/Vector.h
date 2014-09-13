#ifndef COMMON_VECTOR_H
#define COMMON_VECTOR_H

#include <algorithm>
#include <vector>
#include <functional>
#include <cmath>
#include <common/functional/ListProcessing.h>
#include <common/exceptions/CommonExceptions.h>
#include "Math.h"

namespace nprs {

template <typename Scalar>
class Vector {
public:
    Vector(std::initializer_list<Scalar> il)
        : _coords(il)
    {}

    Vector(std::vector<Scalar> const& coords)
        : _coords(coords)
    {}

    Vector(std::vector<Scalar> && coords)
        : _coords(std::move(coords))
    {}

    Scalar& operator[] (int index) const {
        return _coords[index];
    }

    int numDims() const { return _coords.size(); }
    std::vector<Scalar> const& coords() { return _coords; }

    template <typename O>
    double distanceTo(Vector<O> const& other) const {
        return sqrt(sum(
            mapIndexed(_coords, [&] (const Scalar &s, int i) {
                return Math::sqr(s - other[i]);
            })
        ));
    }

    Scalar max(int *outIndex = 0) const {
        return fold<Scalar> (
            _coords,
            [] (const Scalar &prev, const Scalar &curr) {
                return curr > prev ? curr : prev;
            }
        );
    }

    Scalar min(int *outIndex) const {
        return fold<Scalar> (
            _coords,
            [] (const Scalar &prev, const Scalar &curr) {
                return curr < prev ? curr : prev;
            }
        );
    }

    double length() const {
        return sqrt(sum(nprs::map<Scalar, Scalar> (
            _coords,
            [] (const Scalar& val) { return val * val; }
        )));
    }

    Vector<Scalar> normalize() const {
        double len = length();
        return map<Scalar, Scalar> (_coords, [&] (const Scalar &v) { return v / len; });
    }

    template <typename O>
    Vector<Scalar> operator+ (Vector<O> const& other) {
        if (numDims() != other.numDims())
            throw ArgumentException("Vector<Scalar> operator+ (): dimensions must match");

        return
            mapIndexed<Scalar, Scalar>(
                _coords, [&] (const Scalar &v, int i) { return v + other[i]; }
            );
    }

    template <typename O>
    Vector<Scalar> operator- (Vector<O> const& other) {
        if (numDims() != other.numDims())
            throw ArgumentException("Vector<Scalar> operator+ (): dimensions must match");

        return Vector<Scalar>(mapIndexed<Scalar,Scalar>(_coords, [&] (Scalar const& v, int i) { v - other[i]; }));
    }

    Vector<Scalar> operator* (double k) const {
        return mapIndexed<Scalar, Scalar>(_coords, [&] (Scalar const& val, int i) { return val * k; });
    }

    Vector<Scalar> operator/ (double k) const {
        return mapIndexed<Scalar, Scalar>(_coords, [&] (Scalar const& val, int i) { return val / k; });
    }

private:
    std::vector<Scalar> _coords;
};

typedef Vector<double> RealVec;

}

#endif // COMMON_VECTOR_H
