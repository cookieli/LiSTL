cmake_minimum_required(VERSION 3.14)
project(Vector)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vector main.cpp vector.cpp vector.h DeriveAndBase.cpp DeriveAndBase.h)