#include "TrainingSet.h"
#include <common/exceptions/CommonExceptions.h>

using namespace nprs;

TrainingSet::TrainingSet()
{
}

TrainingSet::TrainingSet(TrainingSet && other) 
    : _data(std::move(other._data))
{
}

TrainingSet::~TrainingSet() {
}

TrainingSet& TrainingSet::operator=(TrainingSet && other)  {
    if (this != &other) {
        _data = std::move(other._data);
    }

    return *this;
}

TrainDataItem& TrainingSet::operator()(int index) {
    return _data[index];
}

const TrainDataItem & TrainingSet::operator()(int index) const {
    return _data[index];
}

TrainDataItem const& TrainingSet::getItem(int index) const {
    return _data[index];
}

TrainDataItem& TrainingSet::getItem(int index) {
    return _data[index];
}

void TrainingSet::addItem(const TrainDataItem &item) {
    if (_data.empty()) {
        _featuresCount = item.numDimensions();
    }

    if (item.numDimensions() != numDimensions()) {
        throw ArgumentException("TrainingSet::addItem(): item feature vector size does not match previous items feature vector size");
    }

    _data.push_back(item);
}

TrainDataItem::TrainDataItem(const RealVec &data, float response)
: _data(data), _response(response)
{
}

RealVec TrainingSet::rangeMin() const {
    std::vector<float> minCoords(numDimensions(), 0.0f);
    for (TrainDataItem const& item : _data) {
        for (int i = 0; i < item.numDimensions(); i++) {

        }
    }
}

RealVec TrainingSet::rangeMax() const {

}
