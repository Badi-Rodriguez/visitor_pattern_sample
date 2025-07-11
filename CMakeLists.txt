cmake_minimum_required(VERSION 3.28)
project(visitor_pattern_sample)

set(CMAKE_CXX_STANDARD 20)

add_executable(visitor_pattern_sample main.cpp
        improved-version/AreaVisitor.cpp
        improved-version/Circle.cpp
        improved-version/CompoundShape.cpp
        improved-version/Rectangle.cpp
        improved-version/Triangle.cpp
        improved-version/XMLExportVisitor.cpp
        improved-version/XMLExportVisitor.h)
