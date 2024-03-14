cmake_minimum_required(VERSION 3.0.0)
project(Lab_1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(Lab_1 Lab_1.cpp)
add_executable(main main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
