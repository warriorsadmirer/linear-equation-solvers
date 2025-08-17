cmake_minimum_required(VERSION 3.10)
project(LinearEquationSolvers)

set(CMAKE_CXX_STANDARD 17)

# Checking the existence of source files
foreach(SOURCE_FILE 
    main.cpp
    matrix_io.cpp
    simple_iteration.cpp
    thomas_algorithm.cpp
)
    if(NOT EXISTS "${CMAKE_SOURCE_DIR}/src/${SOURCE_FILE}")
        message(FATAL_ERROR "File src/${SOURCE_FILE} is not found")
    endif()
endforeach()

# Checking header files
foreach(HEADER_FILE
    constants.h
    matrix_io.h
    simple_iteration.h
    thomas_algorithm.h
)
    if(NOT EXISTS "${CMAKE_SOURCE_DIR}/include/${HEADER_FILE}")
        message(FATAL_ERROR "Header file include/${HEADER_FILE} not found")
    endif()
endforeach()

# Creating an executable file
add_executable(solver
    src/main.cpp
    src/matrix_io.cpp
    src/simple_iteration.cpp
    src/thomas_algorithm.cpp
)

# Connecting headers
target_include_directories(solver PRIVATE include)

message(STATUS "The configuration is successful! The project is compiled in: ${CMAKE_SOURCE_DIR}")