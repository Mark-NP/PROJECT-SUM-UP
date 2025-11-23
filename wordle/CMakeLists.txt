cmake_minimum_required(VERSION 3.16)
project(universal LANGUAGES CXX)

set(CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)
# find_package(SFML 2.6.2 COMPONENTS graphics window system REQUIRED)


add_executable(main
    main.cpp
    /home/mnp/Documents/image_processing/justrandom.cpp
    /home/mnp/Documents/image_processing/justrandom.h
)
target_link_libraries(main sfml-system sfml-window sfml-graphics sfml-audio )