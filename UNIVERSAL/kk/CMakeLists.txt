cmake_minimum_required(VERSION 3.16)
project(universal LANGUAGES CXX)

set(CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)

add_executable(main
    main.cpp
)