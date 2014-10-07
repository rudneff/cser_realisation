#ifndef RECSYSTEM_TRAININGSET_H
#define RECSYSTEM_TRAININGSET_H

#include <vector>
#include <common/math/Vector.h>

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
    int numDimensions() const { return _featuresCount; }

    std::vector<TrainDataItem> const& items() const { return _data; }

    std::vector<float> rangeMin() const;
    std::vector<float> rangeMax() const;

private:
    std::vector<TrainDataItem> _data;
    int _featuresCount;
};

class TrainDataItem final {
public:
    TrainDataItem(const RealVec &data, float response);

    const RealVec & data() const { return _data; }
    float response() const { return _response; }
    int numDimensions() const { return _data.numDims(); }

private:
    RealVec _data;
    float _response;
};

}

#endif // RECSYSTEM_TRAININGSET_H
