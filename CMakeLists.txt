cmake_minimum_required(VERSION 3.18)
project(POS_Semestralka)

set(CMAKE_CXX_STANDARD 14)
include_directories(. Game Socket_Klient Socket_Server)
add_executable(POS_Semestralka
        Game/game.cpp
        Game/game.h
        Game/Player.h
        Game/Player.cpp
        Game/Policko.h
        Game/Policko.cpp
        Game/Figurka.h
        Game/Figurka.cpp
        Game/HraciaPlocha.cpp
        Game/HraciaPlocha.h
        Game/Kocka.cpp
        Game/Kocka.h
        socket_client/main.cpp
        socket_client/main.cpp
)

target_link_libraries(POS_Semestralka pthread)