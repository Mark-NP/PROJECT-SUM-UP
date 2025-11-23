cmake_minimum_required(VERSION 3.16)
project(universal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
    main.cpp
    fraction_mode.cpp
    fraction_mode.hpp
)
