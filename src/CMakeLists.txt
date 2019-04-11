cmake_minimum_required(VERSION 3.14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_subdirectory(app)
add_subdirectory(game)
add_subdirectory(pinguim)