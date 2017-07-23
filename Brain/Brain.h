//
// Created by Golubev Kirill on 23/07/2017.
//

#ifndef NEURAL_NET_ATTEMPT_TWO_BRAIN_H
#define NEURAL_NET_ATTEMPT_TWO_BRAIN_H

#include "../Input_Layer/Input_layer.h"
#include "Eigen/Eigen"

namespace Brain {
    class Brain {
    private:
        Input_layer *net;
        double learning_rate;
        Eigen::VectorXd increment;
        Eigen::VectorXd get_param_increment(int params_number);

    public:
        Eigen::MatrixXd get_all_params();

        void set_all_params(Eigen::MatrixXd);

        Brain(Input_layer *net, double learning_rate = 0.01);

        void update_params(double reward);

        int process(Eigen::VectorXd observation);
    };
}


#endif //NEURAL_NET_ATTEMPT_TWO_BRAIN_H
