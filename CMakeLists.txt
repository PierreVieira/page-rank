cmake_minimum_required(VERSION 3.15)
project(DiscretaPGRank C)

set(CMAKE_C_STANDARD 99)

add_executable(DiscretaPGRank main.c src/arrays.c src/arrays.h src/graph.c src/graph.h)