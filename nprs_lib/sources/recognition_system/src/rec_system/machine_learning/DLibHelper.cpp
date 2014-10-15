#include "DLibHelper.h"

namespace nprs {

std::pair<std::vector<dlib::matrix<double>>, std::vector<double>>
    DLibHelper::convertTrainingSet(const TrainingSet &data)
{
    std::vector<dlib::matrix<double>> samples;
    std::vector<double> responses;

    samples.reserve(data.items().size());
    responses.reserve(data.items().size());

    for (TrainDataItem const& item: data.items()) {
        samples.push_back(convertSample(item.data()));
        responses.push_back(item.response());
    }

    return std::make_pair(samples, responses);
}

dlib::matrix<double> DLibHelper::convertSample(const RealVec &item) {
    dlib::matrix<double> s;
    s.set_size(item.numDims(), 1);
    for (int i = 0; i < item.numDims(); i++) {
        s(i) = item[i];
    }

    return s;
}

}
