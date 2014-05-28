#include "Algorithm.h"

nprs::Algorithm::Algorithm(std::function<void()> const& finishedCallback)
    : _finishedCallback(finishedCallback)
{
}

nprs::Algorithm::~Algorithm() {
}
