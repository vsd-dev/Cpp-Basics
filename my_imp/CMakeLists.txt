cmake_minimum_required(VERSION 3.16)
project(Demo)
add_executable(Demo main.cpp)

add_subdirectory(NumCpp)
target_link_libraries(${PROJECT_NAME} NumCore)