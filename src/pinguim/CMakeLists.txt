cmake_minimum_required(VERSION 3.14)

project(pinguim)

add_library(pinguim 
    STATIC
        engine.cpp
        pinguim.cpp
        active.cpp
        player.cpp
)

target_link_libraries(pinguim 
    PUBLIC
        sfml-graphics 
        sfml-audio
)

target_include_directories(pinguim
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

message("Linking for ${PROJECT_NAME}")