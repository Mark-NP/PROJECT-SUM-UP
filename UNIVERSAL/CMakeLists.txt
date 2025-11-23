cmake_minimum_required(VERSION 3.16)
project(universal LANGUAGES CXX)

set(CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)

add_executable(main
    main.cpp
    filemanage.cpp
    filemanage.h
    making.cpp
    making.h
)

target_link_libraries(main ncurses)
