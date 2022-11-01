cmake_minimum_required(VERSION 3.20)
project(Priceladder)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(priceladder main.cpp)
target_link_libraries(priceladder ${CONAN_LIBS})