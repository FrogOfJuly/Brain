cmake_minimum_required(VERSION 3.6)
project(Neural_net_attempt_two_)

set(CMAKE_CXX_STANDARD 11)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
set(SOURCE_FILES main.cpp
        Layer/Layer.cpp
        Layer/Layer.h Input_Layer/Input_layer.cpp Input_Layer/Input_layer.h Dense_Layer/Dense_Layer.cpp Dense_Layer/Dense_Layer.h)
add_executable(Neural_net_attempt_two_ ${SOURCE_FILES})