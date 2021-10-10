cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(task_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")


set(SOURCE_FILES
        # Headers
        code/constants.h
        code/fish.h
        code/animal.h
        code/beast.h
        code/rnd.h
        code/container.h
        code/bird.h

        # Sources
        code/main.cpp
        code/fish.cpp
        code/animal.cpp
        code/beast.cpp
        code/container.cpp
        code/bird.cpp)

add_executable(task_1 ${SOURCE_FILES})