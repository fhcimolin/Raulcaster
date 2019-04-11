cmake_minimum_required(VERSION 3.14)

project(app)

add_executable(app 
    main.cpp
)

target_link_libraries(app 
    PUBLIC
        pinguim
        game
)

target_include_directories(app
    PUBLIC
        ${pinguim_SOURCE_DIR}
)