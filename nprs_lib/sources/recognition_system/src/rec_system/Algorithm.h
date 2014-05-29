#ifndef RECSYSTEM_ALGORITHM_H
#define RECSYSTEM_ALGORITHM_H

#include <functional>

namespace nprs {

class Algorithm {
public:
    explicit Algorithm(std::function<void()> const& finishedCallback);
    virtual ~Algorithm();

    virtual void perform() = 0;

private:
    std::function<void()> _finishedCallback;
};

}

#endif // RECSYSTEM_ALGORITHM_H
