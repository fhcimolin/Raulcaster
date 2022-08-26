cmake_minimum_required(VERSION 3.14)

project(Raulcaster)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_subdirectory(app)
add_subdirectory(game)
add_subdirectory(pinguim)