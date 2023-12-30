cmake_minimum_required(VERSION 3.18)
project(Projekty)

set(CMAKE_CXX_STANDARD 17)

add_executable(pos_semestralka main.cpp  my_socket.cpp my_socket.h)
target_link_libraries(pos_semestralka wsock32 ws2_32)
