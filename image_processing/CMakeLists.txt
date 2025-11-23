cmake_minimum_required(VERSION 3.16)
project(ImageProcessing LANGUAGES CXX)

set(CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)

add_executable(main 
    main.cpp
    img_processing.cpp
    img_processing.h
    justrandom.cpp
    justrandom.h


)
# target_link_libraries(main PUBLIC
#     img_processing.h
# )
