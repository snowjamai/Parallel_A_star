cmake_minimum_required(VERSION 3.19)
project(pa CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(pa main.cu)

set_target_properties(
        pa
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)