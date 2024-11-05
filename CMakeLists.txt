cmake_minimum_required(VERSION 3.30)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 src/main.cpp
        include/toInclude.h
        include/shaker.h
        include/comb.h
        include/selection.h
        include/quick.h
        include/heap.h
        include/insertion.h
        include/merge.h
        include/counting.h
        include/binary_insertion.h
        include/bfs.h
        include/dfs.h
        include/bubble.h
)
