#include "SvmRegressionTrainer.h"
#include "DLibHelper.h"
#include "DLibDecisionMaker.h"
#include <dlib/svm.h>
#include <dlib/statistics.h>
#include <vector>
#include <rec_system/machine_learning/TrainingSet.h>

using namespace std;

namespace nprs {

typedef dlib::matrix<double> sample_type;
typedef dlib::radial_basis_kernel<sample_type> kernel_type;

static dlib::vector_normalizer<sample_type> normalizeData(vector<sample_type> &data);

up<DecisionMaker> SvmRegressionTrainer::train(const TrainingSet &dataSet) {
    auto trainingSet = DLibHelper::convertTrainingSet(dataSet);
    vector<sample_type> samples = trainingSet.first;
    vector<double> responses = trainingSet.second;

//    auto normalizer = normalizeData(samples);
    dlib::randomize_samples(samples, responses);

    dlib::krr_trainer<kernel_type> trainer;
    const double gamma = 3.0/compute_mean_squared_distance(randomly_subsample(samples, 2000));
    trainer.set_kernel(kernel_type(gamma));
    auto decisionFunction = trainer.train(samples, responses);

    return up<DecisionMaker>(new DLibDecisionMaker<kernel_type>(decisionFunction));
}

dlib::vector_normalizer<sample_type> normalizeData(vector<sample_type> &data) {
    dlib::vector_normalizer<sample_type> normalizer;
    normalizer.train(data);

    for (int i = 0; i < data.size(); i++) {
        data[i] = normalizer(data[i]);
    }

    return normalizer;
}

}
