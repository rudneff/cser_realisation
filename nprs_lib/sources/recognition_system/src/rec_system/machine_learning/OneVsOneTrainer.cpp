#include "OneVsOneTrainer.h"

#include "TrainingSet.h"
#include "DLibHelper.h"
#include "DLibDecisionMaker.h"
#include <dlib/svm_threaded.h>

namespace nprs {

OneVsOneTrainer::OneVsOneTrainer() {
}

up<DecisionMaker> OneVsOneTrainer::train(const TrainingSet &dataSet) {
    typedef dlib::matrix<double> sample_type;
    typedef dlib::radial_basis_kernel<sample_type> kernel_type;

    typedef dlib::one_vs_one_trainer<dlib::any_trainer<sample_type> > ovo_trainer;

    auto set = DLibHelper::convertTrainingSet(dataSet);
    dlib::randomize_samples(set.first, set.second);

    dlib::krr_trainer<kernel_type> rbf_trainer;
    rbf_trainer.set_kernel(0.1);

    ovo_trainer trainer;
    trainer.set_trainer(rbf_trainer);

    dlib::one_vs_one_decision_function<ovo_trainer> df = trainer.train(set.first, set.second);
}

}
