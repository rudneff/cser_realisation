#ifndef COMMON_COMMONDEFINITIONS_H
#define COMMON_COMMONDEFINITIONS_H

#include <memory>

using uchar = unsigned char;
template <typename T> using sp = std::shared_ptr<T>;
template <typename T> using wp = std::weak_ptr<T>;
template <typename T> using up = std::unique_ptr<T>;

#endif // COMMON_COMMONDEFINITIONS_H
