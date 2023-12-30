cmake_minimum_required(VERSION 3.18)
project(POS_Semestralka)

set(CMAKE_CXX_STANDARD 14)
include_directories(. Socket_Server)

add_executable(POS_Semestralka Socket_Server/main.c Socket_Server/active_socket.c Socket_Server/active_socket.h
        Socket_Server/char_buffer.h Socket_Server/char_buffer.c Socket_Server/passive_socket.c
        Socket_Server/passive_socket.h
        Game/game.cpp
        Game/game.h
        Game/Player.h
        Socket_Server/main.c
        Game/Player.cpp
        Game/Policko.h
        Game/Policko.cpp
        Game/Figurka.h
        Game/Figurka.cpp
)
target_link_libraries(POS_Semestralka pthread)