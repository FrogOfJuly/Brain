//
// Created by Golubev Kirill on 21/07/2017.
//

#include "Layer.h"
#include <iostream>

Brain::Layer::Layer() {
    this->next = nullptr;
    this->prev = nullptr;
}

Brain::Layer::Layer(Layer *net) {
    net->attach(this);
    this->next = nullptr;
}

void Brain::Layer::attach(Layer *layer) {
    if (this->next == nullptr) {
        this->next = layer;
        layer->prev = this;
    } else
        this->next->attach(layer);
}

Eigen::VectorXd Brain::Layer::transform(Eigen::VectorXd input) {
    return input;
}

using std::endl;
using std::cout;

Eigen::VectorXd Brain::Layer::calculate(Eigen::VectorXd input) {
    Eigen::VectorXd tmp = transform(input);
    if (this->next == nullptr)
        return tmp;
    return this->next->calculate(tmp);
}

using std::cerr;

void Brain::attaching_test() {
    Brain::Layer net;
    Brain::Layer layer(&net);
    Brain::Layer another_layer(&net);
    if (net.next != &layer) {
        cerr << "attaching test failed" << endl;
        return;
    }
    if (net.next->next != &another_layer) {
        cerr << "attaching test failed" << endl;
        return;
    }
    if (net.next->next->next != nullptr) {
        cerr << "attaching test failed" << endl;
    }
    cout << "attaching test passed" << endl;
}

void Brain::passing_test() {
    Brain::Layer net;
    Brain::Layer layer(&net);
    Brain::Layer another_layer(&net);
    Eigen::VectorXd input(10);
    for (int i = 0; i < 10; i++)
        input[i] = i;
    if (net.calculate(input) == input)
        cout << "passing test passed" << endl;
    else
        cerr << "passing test failed" << endl;
}

void Brain::length_test() {
    Brain::Layer net;
    Brain::Layer layer(&net);
    Brain::Layer another_layer(&net);
    if (net.get_length() == 3)
        cout << "length test passed" << endl;
    else
        cerr << "length test failed" << endl;

}

int Brain::Layer::get_unit_number() {
    return 0;
}

int Brain::Layer::get_length() {
    if (this->next == nullptr)
        return 1;
    else
        return (1 + next->get_length());
}

Eigen::VectorXd Brain::Layer::get_all_params() {
    ;
}

void Brain::Layer::set_all_params(Eigen::VectorXd params){
    ;
}

