cmake_minimum_required(VERSION 3.17)
project(task_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")

set(SOURCE_FILES
        # Headers
        code/animal.h
        code/beast.h
        code/bird.h
        code/constants.h
        code/container.h
        code/fish.h
        code/rnd.h

        # Sources
        code/animal.cpp
        code/beast.cpp
        code/bird.cpp
        code/container.cpp
        code/fish.cpp
        code/main.cpp
        )

add_executable(task_2 ${SOURCE_FILES})