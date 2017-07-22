//
// Created by Golubev Kirill on 21/07/2017.
//

#ifndef NEURAL_NET_ATTEMPT_TWO_LAYER_H
#define NEURAL_NET_ATTEMPT_TWO_LAYER_H

#include "Eigen/Eigen"

namespace Brain {
    class Layer {
    protected:
        Layer *next, *prev;
        void attach(Layer *net);
        virtual Eigen::VectorXd transform(Eigen::VectorXd input);
    public:
        Layer(Layer *net);
        Layer();
        Eigen::VectorXd calculate(Eigen::VectorXd);
        virtual int get_unit_number();
        friend void attaching_test();
        friend void passing_test();
    };

    void attaching_test();
    void passing_test();
}

#endif //NEURAL_NET_ATTEMPT_TWO_LAYER_H
