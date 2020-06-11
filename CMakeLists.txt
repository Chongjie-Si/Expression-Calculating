cmake_minimum_required(VERSION 3.14)
project(Expression)

set(CMAKE_CXX_STANDARD 14)

set(Python_ADDITIONAL_VERSIONS 3.6)

find_package(PythonLibs 3 REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(Expression main.cpp equation_common.h cmake-build-debug equation.h integral_limitation.h)

target_link_libraries(Expression ${PYTHON_LIBRARIES})
