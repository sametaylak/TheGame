cmake_minimum_required(VERSION 3.24)
project(glad C)

set(CMAKE_C_STANDARD 11)

add_library(glad src/glad.c)
include_directories(include)

target_include_directories(glad PUBLIC include)
