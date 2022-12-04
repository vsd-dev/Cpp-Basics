cmake_minimum_required(VERSION 3.21.0)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_CROSSCOMPILING, TRUE)
project(HELLO)
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Adder)
target_link_libraries(${PROJECT_NAME} adder)