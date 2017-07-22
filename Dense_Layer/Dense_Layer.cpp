//
// Created by Golubev Kirill on 21/07/2017.
//

#include "Dense_Layer.h"
#include "../Input_Layer/Input_layer.h"
#include <iostream>

template<double (*activation_function)(double), double (*derivative)(double)>
Brain::Dense_Layer<activation_function, derivative>::Dense_Layer(Layer *net, int unit_number):Layer(net) {
    this->act_func = activation_function;
    this->grad = derivative;
    this->unit_number = unit_number;
    init();
}

template<double (*activation_function)(double), double (*derivative)(double)>
Eigen::VectorXd Brain::Dense_Layer<activation_function, derivative>::transform(Eigen::VectorXd input) {
    Eigen::VectorXd watch = input;
    Eigen::MatrixXd W = (this->W);
    Eigen::VectorXd b = (this->b);
    Eigen::VectorXd tmp_vector = W*watch;
    tmp_vector+=b;
    Eigen::VectorXd tmp = activation(tmp_vector);
    return tmp;
}

template<double (*activation_function)(double), double (*derivative)(double)>
Eigen::VectorXd Brain::Dense_Layer<activation_function, derivative>::activation(Eigen::VectorXd input) {
    Eigen::VectorXd output(this->unit_number);
    for (int i = 0; i < this->unit_number; i++)
        output[i] = this->act_func(input[i]);
    return output;
}

template<double (*activation_function)(double), double (*derivative)(double)>
void Brain::Dense_Layer<activation_function, derivative>::init() {
    this->W = Eigen::MatrixXd::Random(this->get_unit_number(), this->prev->get_unit_number());
    this->b = Eigen::MatrixXd::Random(this->get_unit_number(), 1);
}

template<double (*activation_function)(double), double (*derivative)(double)>
int Brain::Dense_Layer<activation_function, derivative>::get_unit_number() {
    return this->unit_number;
}

double Brain::dsigmoid(double x){
    return sigmoid(x)*(sigmoid(x) - 1.0);
};

double Brain::sigmoid(double x){
    return 1.0/(1.0 + exp(-x));
}


using std::cout;
using std::endl;

void Brain::test_Dense_layer() {
    Brain::Input_layer net(3);
    Brain::SigmoidLayer hid_layer1(&net, 5);
    Brain::LinearLayer hid_layer2(&net, 7);
    Brain::Binary_stepLayer hid_layer3(&net, 8);
    Brain::TanHLayer hid_layer4(&net, 9);
    Brain::RelULayer hid_layer5(&net, 10);
    Eigen::VectorXd input(3);
    for(int i = 0; i < 3; i++)
        input[i] = i;
    auto tmp = net.calculate(input);
    cout<<"Dense layer test passed"<<endl;
}

double ::Brain::identity(double x) {
    return x;
}

double ::Brain::didentity(double x) {
    return 1.0;
}

double ::Brain::binary_step(double x) {
    if (x > 0)
        return 1;
    else
        return 0;
}

double ::Brain::dbinary_step(double x) {
    return 0;
}

double ::Brain::tanH(double x) {
    return 2.0/(1 + exp(-2*x)) - 1.0;
}

double Brain::dtanH(double x) {
    return 1 - tanH(x)*tanH(x);
}

double ::Brain::RelU(double x) {
    if(x < 0)
        return 0;
    else
        return x;
}

double ::Brain::dRelu(double x) {
    if(x < 0)
        return 0;
    else
        return 1;
}
