cmake_minimum_required(VERSION 3.18)
project(socket_client)

set(CMAKE_CXX_STANDARD 17)

add_executable(socket_client main.cpp)
target_link_libraries(socket_client wsock32 ws2_32)
