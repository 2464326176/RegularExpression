cmake_minimum_required(VERSION 3.13)


set(CMAKE_CXX_STANDARD 11)



add_executable(opencv
        cplus/main.cpp
        cplus/CommonFunction.cpp
        cplus/CommonFunction.h
        cplus/CalculateCpuTime.h)
#添加动态链接库


