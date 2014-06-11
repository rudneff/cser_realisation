#ifndef RECSYSTEM_TRAININGSET_H
#define RECSYSTEM_TRAININGSET_H

#include <vector>

namespace nprs {

class TrainDataItem;

class TrainingSet final {
public:
    TrainingSet();
    ~TrainingSet();

    TrainingSet(TrainingSet && other);
    TrainingSet& operator= (TrainingSet && other);

    TrainDataItem&  operator() (int index);
    const TrainDataItem & operator() (int index) const;

    TrainDataItem & getItem(int index);
    const TrainDataItem & getItem(int index) const;

    void addItem(const TrainDataItem& item);

    int size() const { return _data.size(); }
    int featuresCount() const { return _featuresCount; }

private:
    std::vector<TrainDataItem> _data;
    int _featuresCount;
};

class TrainDataItem final {
public:
    TrainDataItem(const std::vector<float> &data, float response);

    const std::vector<float> & data() const { return _data; }
    float response() const { return _response; }
    int featuresCount() { return _data.size(); }

private:
    std::vector<float> _data;
    float _response;
};

}

#endif // RECSYSTEM_TRAININGSET_H
