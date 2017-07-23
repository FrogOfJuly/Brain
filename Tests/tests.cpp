//
// Created by Golubev Kirill on 22/07/2017.
//
#include "iostream"
#include "gsl/gsl_randist.h"
#include "tests.h"

void Brain::gsl_test() {
    gsl_rng_env_setup();
    double x[10], check = 0;
    const gsl_rng_type *T;
    gsl_rng *r;
    T = gsl_rng_default;
    r = gsl_rng_alloc(T);
    gsl_ran_dir_nd(r, 10, x);
    for (int i = 0; i < 10; i++) {
        check += x[i] * x[i];
    }
    gsl_rng_free (r);
    std::cout<<"gsl is probably working"<<std::endl;
}
