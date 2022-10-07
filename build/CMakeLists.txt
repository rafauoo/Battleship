cmake_minimum_required(VERSION 3.10)

# set the project name
project(Statki)

find_package(SFML REQUIRED system window graphics network audio)


set(SFML_LIBRARIES sfml-system
        sfml-window
        sfml-graphics
        sfml-network
        sfml-audio)

# Graphic Library

set(graphic_lib_dir ../lib/Graphic)
set(graphic_lib_sources
        ${graphic_lib_dir}/Window.cpp
        ${graphic_lib_dir}/MenuWindow.cpp
        )
add_library(graphic-lib ${graphic_lib_sources})

# Logic library
set(logic_lib_dir ../lib/Logic)
set(logic_lib_sources
        ${logic_lib_dir}/Menu.cpp
        )
add_library(logic-lib ${logic_lib_sources})

# Game library
set(game_lib_dir ../lib/Game)
set(game_lib_sources
        ${game_lib_dir}/Game.cpp
        )
add_library(game-lib ${game_lib_sources})

# Events library
set(events_lib_dir ../lib/Events)
set(events_lib_sources
        ${events_lib_dir}/Event.cpp
        )
add_library(events-lib ${events_lib_sources})

# Core library
set(core_lib_dir ../lib/Core)
set(core_lib_sources
        ${core_lib_dir}/Clock.cpp
        )
add_library(core-lib ${core_lib_sources})

# add the executable
add_executable(statki ../main.cpp ${core_lib_sources} ${graphic_lib_sources} ${logic_lib_sources} ${game_lib_sources} ${events_lib_sources})
target_link_libraries(statki ${SFML_LIBRARIES} graphic-lib logic-lib game-lib events-lib core-lib)

