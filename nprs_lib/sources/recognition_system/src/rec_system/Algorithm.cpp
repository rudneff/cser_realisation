#include "Algorithm.h"

nprs::Algorithm::Algorithm(const std::function<void()> &finishedCallback)
    : _finishedCallback(finishedCallback)
{
}

nprs::Algorithm::~Algorithm() {
}
