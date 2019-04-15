cmake_minimum_required(VERSION 3.14)

project(game)

add_library(game 
    STATIC
        game.cpp
        mapReader.cpp
        map.cpp
)

target_link_libraries(game 
    PUBLIC
        pinguim
        sfml-graphics 
        sfml-audio
)

target_include_directories(game
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

message("Linking for ${PROJECT_NAME}")