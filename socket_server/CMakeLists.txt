cmake_minimum_required(VERSION 3.18)
project(socket_server)

set(CMAKE_CXX_STANDARD 17)
include_directories(. Game)

add_executable(socket_server
        ../Game/Game.cpp
        ../Game/Game.h
        ../Game/Player.h
        ../Game/Player.cpp
        ../Game/Policko.h
        ../Game/Policko.cpp
        ../Game/Figurka.h
        ../Game/Figurka.cpp
        ../Game/HraciaPlocha.cpp
        ../Game/HraciaPlocha.h
        ../Game/Kocka.cpp
        ../Game/Kocka.h
        main.cpp
)


target_link_libraries(socket_server pthread)