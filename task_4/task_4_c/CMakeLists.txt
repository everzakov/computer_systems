cmake_minimum_required(VERSION 3.17)
project(task_4_c C)

set(CMAKE_C_STANDARD 99)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES

        # Headers
        code/constants.h
        code/extdata.h

        # Sources
        code/input.c
        code/inrnd.c
        code/output.c
        code/main.c

        )

add_executable(task_4_c ${SOURCE_FILES})