//
// Created by Golubev Kirill on 23/07/2017.
//

#include "Brain.h"
#include "gsl/gsl_randist.h"
#include <iostream>

using std::cerr;
using std::endl;


Eigen::VectorXd Brain::Brain::get_param_increment() {
    double increment[this->params_number];
    gsl_rng_env_setup();
    const gsl_rng_type *T;
    gsl_rng *r;
    T = gsl_rng_default;
    r = gsl_rng_alloc(T);
    gsl_ran_dir_nd(r, (size_t) (this->params_number), increment);
    gsl_rng_free(r);
    Eigen::VectorXd inc(this->params_number);
    for (int i = 0; i < this->params_number; i++)
        inc[i] = increment[i];
    this->increment = inc;
    return inc;
}

Eigen::MatrixXd Brain::Brain::get_all_params() {
    return this->net->get_all_params();
}

Brain::Brain::Brain(Input_layer *net, double learning_rate) {
    this->net = net;
    this->learning_rate = learning_rate;
    auto params = get_all_params();
    this->params_number = params.rows()*params.cols();
}

void Brain::Brain::set_all_params(Eigen::MatrixXd Params) {
    long int rows = this->get_all_params().rows();
    long int cols = this->get_all_params().cols();
    if (Params.rows() != rows || Params.cols() != cols) {
        cerr << "wrong number of elements " << Params.rows() * Params.cols() << " instead of " << cols * rows << endl;
        throw;
    } else
        this->net->set_all_params(Params);
}

void Brain::Brain::update_params(double reward) {
    auto cur_params = this->get_all_params();
    cur_params += -learning_rate * this->increment + reward * learning_rate * this->increment;
    this->set_all_params(cur_params);
}

int Brain::Brain::process(Eigen::VectorXd observation) {
    auto output = net->calculate(observation);
    int idx = 0;
    double max = output(idx);
    for (int i = 0; i < output.rows(); i++) {
        if (max < output(i)) {
            max = output(i);
            idx = i;
        }
    }
    return idx;
}

void Brain::Brain::apply_param_increment(double alpha) {
    auto inc = alpha*this->get_param_increment();
    auto params = this->get_all_params();
    this->set_all_params(params + inc);
}


