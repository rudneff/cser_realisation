#ifndef COMMON_VECTOR_H
#define COMMON_VECTOR_H

#include <algorithm>
#include <vector>
#include <functional>
#include <cmath>
#include <common/functional/ListProcessing.h>
#include <common/exceptions/CommonExceptions.h>

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
        return 0;
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
        std::vector<Scalar> ncoords(numDims());
        double len = length();
        for (int i = 0; i < numDims(); i++) {
            ncoords[i] = static_cast<Scalar> (_coords[i] / len);
        }
        return Vector<Scalar>(std::move(ncoords));
    }

    template <typename O>
    Vector<Scalar> operator+ (Vector<O> const& other) {
        if (numDims() != other.numDims())
            throw ArgumentException("Vector<Scalar> operator+ (): dimensions must match");

        return Vector<Scalar>(map<Scalar>([&] (Scalar v, int i) { return v + other[i]; }));
    }

    template <typename O>
    Vector<Scalar> operator- (Vector<O> const& other) {
        if (numDims() != other.numDims())
            throw ArgumentException("Vector<Scalar> operator+ (): dimensions must match");

        return Vector<Scalar>(map<Scalar>([&] (Scalar v, int i) { v - other[i]; }));
    }

    Scalar operator* (Scalar k) {
        return map<Scalar>([&] (Scalar val, int i) { return val * k; });
    }

    Scalar operator/ (Scalar k) {
        return map<Scalar>([&] (Scalar val, int i) { return val / k; });
    }

    template <typename O>
    Vector<O> map(std::function<O (Scalar, int)> func) {
        std::vector<O> newCoords(numDims());
        for (int i = 0; i < _coords.size(); i++) {
            newCoords[i] = func(_coords[i], i);
        }
        return Vector<O>(std::move(newCoords));
    }

private:
    std::vector<Scalar> _coords;
};

}

#endif // COMMON_VECTOR_H
