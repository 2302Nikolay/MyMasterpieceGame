cmake_minimum_required(VERSION 3.10)

project(game LANGUAGES CXX)

add_executable(game 
    main.cpp 
    src/Character.cpp 
    src/Player.cpp 
    src/PlayerController.cpp
    src/Enemy.cpp
    src/Camera.cpp
    )

target_link_libraries(game PRIVATE sfml-graphics)
target_link_libraries(game PRIVATE sfml-window)
target_link_libraries(game PRIVATE sfml-system)