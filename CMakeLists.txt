cmake_minimum_required(VERSION 3.20)
project(Preisleiter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(preisleiter
    # Application
    main.cpp
    
    # Mainwindown
    preisleiter.cpp
    preisleiter.h
    
    # TimerSetupDialog
    timer_setup_dialog.cpp
    timer_setup_dialog.h)

qt5_use_modules(preisleiter Core Widgets)
