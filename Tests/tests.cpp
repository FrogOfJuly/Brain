//
// Created by Golubev Kirill on 22/07/2017.
//
#include "iostream"
#include "gsl/gsl_randist.h"
#include "tests.h"
#include "../Brain/Brain.h"
#include "../Input_Layer/Input_layer.h"
#include "../Dense_Layer/Dense_Layer.h"

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

void Brain::Brain_test(){
    Input_layer net(10);
    SigmoidLayer hidden_layer1(&net, 11);
    SigmoidLayer hidden_layer2(&net, 13);
    SigmoidLayer hidden_layer3(&net, 17);
    Brain brain(&net);
    auto params = brain.get_all_params();
    brain.set_all_params(params);
    std::cout<<"test for getting and setting all params passed"<<std::endl;
}
