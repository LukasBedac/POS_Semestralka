cmake_minimum_required(VERSION 3.18)
project(socket_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(socket_server main.cpp
        ../Game/game.cpp
        ../Game/game.h
        ../Game/Player.h
        ../Game/Player.cpp
        ../Game/Policko.h
        ../Game/Policko.cpp
        ../Game/Figurka.h
        ../Game/Figurka.cpp
        ../Game/HraciaPlocha.cpp
        ../Game/HraciaPlocha.h
        ../Game/Kocka.cpp
        ../Game/Kocka.h)

target_link_libraries(socket_server pthread)