cmake_minimum_required(VERSION 3.10)
project(LinearEquationSolvers)

set(CMAKE_CXX_STANDARD 17)

# Проверка существования исходных файлов
foreach(SOURCE_FILE 
    main.cpp
    matrix_io.cpp
    simple_iteration.cpp
    thomas_algorithm.cpp
)
    if(NOT EXISTS "${CMAKE_SOURCE_DIR}/src/${SOURCE_FILE}")
        message(FATAL_ERROR "Файл src/${SOURCE_FILE} не найден!")
    endif()
endforeach()

# Проверка заголовочных файлов
foreach(HEADER_FILE
    constants.h
    matrix_io.h
    simple_iteration.h
    thomas_algorithm.h
)
    if(NOT EXISTS "${CMAKE_SOURCE_DIR}/include/${HEADER_FILE}")
        message(FATAL_ERROR "Заголовочный файл include/${HEADER_FILE} не найден!")
    endif()
endforeach()

# Создание исполняемого файла
add_executable(solver
    src/main.cpp
    src/matrix_io.cpp
    src/simple_iteration.cpp
    src/thomas_algorithm.cpp
)

# Подключение заголовков
target_include_directories(solver PRIVATE include)

message(STATUS "Конфигурация успешна! Проект собран в: ${CMAKE_SOURCE_DIR}")