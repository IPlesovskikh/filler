cmake_minimum_required(VERSION 3.15)
project(filler C)

set(CMAKE_C_STANDARD 99)

add_executable(filler main.c filler.h get_maps.c error.c)