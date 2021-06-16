cmake_minimum_required(VERSION 3.13)


set(CMAKE_CXX_STANDARD 11)



add_executable(opencv
        main.cpp
        CommonFunction.cpp
        CommonFunction.h
        CalculateCpuTime.h)
#添加动态链接库


