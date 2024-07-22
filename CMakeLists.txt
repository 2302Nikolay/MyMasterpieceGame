cmake_minimum_required(VERSION 3.10)

project(game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

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

# Укажите путь к SFML
#set(SFML_DIR "/home/nik/Desktop/sfl/Lib/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/lib/cmake/SFML")
#find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

target_link_libraries(game PRIVATE sfml-graphics sfml-window sfml-system)
