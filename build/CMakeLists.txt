cmake_minimum_required(VERSION 3.10)

# set the project name
project(Statki)

find_package(SFML REQUIRED system window graphics network audio)

set(SFML_INCLUDE_DIR ../lib/SFML/include)
set(SFML_LIBRARIES sfml-system
        sfml-window
        sfml-graphics
        sfml-network
        sfml-audio)

# Graphic Library

set(graphic_lib_dir ../lib/Graphic)
set(graphic_lib_sources
        ${graphic_lib_dir}/Board.cpp
        )

add_library(graphic-lib ${graphic_lib_sources})

# add the executable
add_executable(statki ../main.cpp)
target_link_libraries(statki ${SFML_LIBRARIES} graphic-lib)

