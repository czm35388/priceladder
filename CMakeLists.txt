cmake_minimum_required(VERSION 3.20)
project(Priceladder)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(priceladder 
	main.cpp
	preisleiter.cpp
	preisleiter.h
	preisleiter.ui)

target_link_libraries(priceladder Qt5::Widgets)