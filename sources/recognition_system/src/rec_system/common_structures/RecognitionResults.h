#ifndef RECSYSTEM_RECOGNITIONRESULTS_H
#define RECSYSTEM_RECOGNITIONRESULTS_H

#include <vector>
#include <memory>

namespace nprs {

class NumberPlate; using pNumberPlate = std::shared_ptr<NumberPlate>;

class RecognitionResults {
public:
    RecognitionResults(const std::vector<pNumberPlate> &numberPlates)
            : _numberPlates(numberPlates)
    {}

    std::vector<pNumberPlate> const & numberPlates() const { return _numberPlates; }

private:
    std::vector<pNumberPlate> _numberPlates;
};

}

#endif
