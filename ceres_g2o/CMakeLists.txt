cmake_minimum_required(2.8)
project( useg2o )
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-O3" )

find_package(g2o)
include_directories(${g2o_INCLUDE_DIRS})

add_executable(use_g2o use_g2o.cpp)
target_link_libraries()