cmake_minimum_required(VERSION 3.12)
project(bis_gg_resolve_sudoku_with_coloring)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        bis_gg_resolve_sudoku_with_coloring
        main.cpp
        include/graph.hpp
        include/sudoku.hpp
        src/Graph.cpp src/Sudoku.cpp)