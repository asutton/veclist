
cmake_minimum_required(VERSION 3.0)

enable_testing()

# Make sure that we're compiling C++14 source code.
set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(test-list list.cpp)
add_executable(test-vector vector.cpp)
add_executable(test-vector-binary vector-binary.cpp)
add_executable(test-vector-sort vector-sort.cpp)
add_executable(test-set set.cpp)
