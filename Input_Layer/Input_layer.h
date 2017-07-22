//
// Created by Golubev Kirill on 21/07/2017.
//

#ifndef NEURAL_NET_ATTEMPT_TWO_INPUT_LAYER_H
#define NEURAL_NET_ATTEMPT_TWO_INPUT_LAYER_H

#include "../Layer/Layer.h"
namespace Brain {
    class Input_layer : public Layer {
    protected:
        int unit_number;
        Eigen::VectorXd transform(Eigen::VectorXd);
    public:
        int get_unit_number();
        Input_layer(int unit_number);
        friend void test_Input_layer();
    };

    void test_Input_layer();
}

#endif //NEURAL_NET_ATTEMPT_TWO_INPUT_LAYER_H
