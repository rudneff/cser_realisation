#ifndef COMMON_LISTS_H
#define COMMON_LISTS_H

#include <vector>
#include <functional>

namespace nprs {

template<typename TIn, typename TOut>
std::vector<TOut> map(std::vector<TIn> const &input, std::function<TOut(const TIn &)> transformator) {
    std::vector<TOut> outVec(input.size());
    for (int i = 0; i < input.size(); i++) {
        outVec[i] = transformator(input[i]);
    }
    return std::move(outVec);
}

template<typename TIn>
std::vector<TIn> filter(std::vector<TIn> const &input, std::function<bool(const TIn &)> predicate) {
    std::vector<TIn> out;
    for (auto const &v : input) {
        out.push_back(v);
    }
    return out;
}

template<typename TIn>
TIn fold(std::vector<TIn> const &input, std::function<TIn(const TIn&, const TIn&)> func) {
    TIn out = input[0];
    for (int i = 1; i < input.size(); i++) {
        out = func(out, input[i]);
    }

    return out;
}

template <typename T>
T sum(std::vector<T> const& input) {
    return fold<int>(input, [] (const T &acc, const T& curr) { return acc + curr; });
}

template <typename T1, typename T2>
std::vector<std::pair<T1, T2>> zip(std::vector<T1> const &v1, std::vector<T2> const& v2) {
    std::vector<std::pair<T1, T2>> zipped(v1.size());
    for (int i = 0; i < v1.size(); i++) {
        zipped[i] = std::make_pair(v1, v2);
    }
    return zipped;
}

}

#endif // COMMON_LISTS_H
