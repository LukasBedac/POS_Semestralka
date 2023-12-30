cmake_minimum_required(VERSION 3.18)
project(POS_Semestralka)

set(CMAKE_CXX_STANDARD 14)
include_directories(.)

add_executable(POS_Semestralka main.c Socket_Server/active_socket.c Socket_Server/active_socket.h
                Socket_Server/char_buffer.h Socket_Server/char_buffer.c Socket_Server/passive_socket.c
                Socket_Server/passive_socket.h)
target_link_libraries(POS_Semestralka pthread)