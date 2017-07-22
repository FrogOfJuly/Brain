#include <iostream>
#include "./Layer/Layer.h"
#include "./Input_Layer/Input_layer.h"
#include "./Dense_Layer/Dense_Layer.h"

int main() {
    /*Eigen::MatrixXd Test_Matrix(5, 3);
    Eigen::VectorXd Test_Vector(3);
    std::cout << Test_Matrix << std::endl;
    std::cout << "---------------------" << std::endl;

    std::cout << Test_Vector << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << Test_Matrix * Test_Vector << std::endl;
     */
    Brain::attaching_test();
    Brain::passing_test();
    Brain::test_Input_layer();
    Brain::test_Dense_layer();
    return 0;
}
