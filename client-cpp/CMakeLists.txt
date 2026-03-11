cmake_minimum_required(VERSION 3.16)
project(SnakeClient)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(SnakeClient src/main.cpp)

target_link_libraries(SnakeClient
    SFML::Graphics
    SFML::Window
    SFML::System
)