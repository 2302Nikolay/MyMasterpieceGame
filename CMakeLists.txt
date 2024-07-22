cmake_minimum_required(VERSION 3.10)

project(game LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 20)

add_executable(game 
    main.cpp 
    src/Character.cpp 
    src/Player.cpp 
    src/PlayerController.cpp
    src/Enemy.cpp
    src/Camera.cpp
    src/Menu.cpp
    src/Minimap.cpp
    src/func.cpp
    )

target_link_libraries(game PRIVATE sfml-graphics)
target_link_libraries(game PRIVATE sfml-window)
target_link_libraries(game PRIVATE sfml-system)