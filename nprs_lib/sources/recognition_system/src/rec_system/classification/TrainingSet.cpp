#include "TrainingSet.h"

using namespace nprs;

TrainingSet::TrainingSet(int featuresCount)
    : _featuresCount(featuresCount)
{
}
TrainingSet::TrainingSet(TrainingSet && other) 
    : _data(std::move(other._data))
{
}

TrainingSet& TrainingSet::operator=(TrainingSet && other) 
{
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
    _data.push_back(item);
}

TrainDataItem::TrainDataItem(std::vector<float> const& data, float response) {
    _data = data;
}
