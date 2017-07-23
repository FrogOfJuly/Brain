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

        int get_length();

        virtual int get_unit_number();

        virtual Eigen::VectorXd get_all_params();

        virtual void set_all_params(Eigen::VectorXd);

        friend void attaching_test();

        friend void passing_test();
    };

    void attaching_test();

    void passing_test();

    void length_test();
}

#endif //NEURAL_NET_ATTEMPT_TWO_LAYER_H
