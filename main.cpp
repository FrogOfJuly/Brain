#include <iostream>
#include "./Layer/Layer.h"
#include "./Input_Layer/Input_layer.h"
#include "./Dense_Layer/Dense_Layer.h"
#include "./Tests/tests.h"

using std::cout;
using std::endl;

int main() {


//    Eigen::MatrixXd Test_Matrix = Eigen::MatrixXd::Random(3,4);
//    cout<<Test_Matrix<<endl;
//    cout<<Test_Matrix(12 - 1)<<endl;

    Brain::attaching_test();
    Brain::passing_test();
    Brain::test_Input_layer();
    Brain::test_Dense_layer();
    Brain::gsl_test();
    Brain::test_params_setter_and_getter();
    return 0;
}
