cmake_minimum_required(VERSION 3.18)
project(POS_Semestralka)

set(CMAKE_CXX_STANDARD 14)
include_directories(. Socket_Server)

add_executable(POS_Semestralka main.c Socket_Server/active_socket.c Socket_Server/active_socket.h
        Socket_Server/char_buffer.h Socket_Server/char_buffer.c Socket_Server/passive_socket.c
        Socket_Server/passive_socket.h
        Game/game.cpp
        Game/game.h
        Game/Kocka.h
        Game/Kocka.cpp
        Game/HraciaPlocha.h
        Game/HraciaPlocha.cpp
)
target_link_libraries(POS_Semestralka pthread)