cmake_minimum_required(VERSION 3.23)
project(ICP_Project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ICP_Project2 main.cpp
        node.cpp node.h
        Path.cpp Path.h
        algo.cpp algo.h
        readFiles.cpp readFiles.h
)
