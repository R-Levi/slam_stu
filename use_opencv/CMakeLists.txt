cmake_minimum_required( VERSION 2.8 )
project( useOpencv )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-O3" )

# 添加Eigen头文件
include_directories("/usr/include/eigen3")

find_package(Opencv)
include_directories(${Opencv_INCLUDE_DIRS})

add_executable( use_opencv use_opencv.cpp )