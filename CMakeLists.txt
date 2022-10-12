cmake_minimum_required(VERSION 3.23)
project(Calculator_plus_plus)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(src)

add_executable(Calculator_plus_plus
        src/main.cpp)
