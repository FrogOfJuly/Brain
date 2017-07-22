//
// Created by Golubev Kirill on 21/07/2017.
//

#include "Input_layer.h"
#include <iostream>

Brain::Input_layer::Input_layer(int unit_number) : Layer() {
    this->unit_number = unit_number;
}

Eigen::VectorXd Brain::Input_layer::transform(Eigen::VectorXd input) {
    return input;
}

using std::cerr;
using std::endl;
using std::cout;

void Brain::test_Input_layer() {
    Input_layer inputLayer(11);
    Layer layer(&inputLayer);
    Layer another_layer(&inputLayer);
    Eigen::VectorXd input(10);
    for (int i = 0; i < 10; i++)
        input[i] = i;
    if (inputLayer.calculate(input) == input)
        cout << "passing test for input layer passed" << endl;
    else
        cerr << "passing test for input layer failed" << endl;
}

int Brain::Input_layer::get_unit_number() {
    return this->unit_number;
}
