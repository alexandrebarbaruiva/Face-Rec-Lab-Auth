cmake_minimum_required(VERSION 2.8)
project(LabSis)
set( SRC main.cpp)
add_definitions(-std=c++11)
add_executable( ${PROJECT_NAME} ${SRC} )
