//
// Created by Golubev Kirill on 23/07/2017.
//

#include "Brain.h"
#include "gsl/gsl_randist.h"

Eigen::VectorXd Brain::Brain::get_param_increment(const int params_numer) {
    double increment[params_numer];
    gsl_rng_env_setup();
    const gsl_rng_type *T;
    gsl_rng *r;
    T = gsl_rng_default;
    r = gsl_rng_alloc(T);
    gsl_ran_dir_nd(r, (size_t)(params_numer), increment);
    gsl_rng_free (r);
    Eigen::VectorXd inc(params_numer);
    for(int i = 0; i < params_numer; i++)
        inc[i] = increment[i];
    return inc;
}

Eigen::MatrixXd Brain::Brain::get_all_params() {

}


