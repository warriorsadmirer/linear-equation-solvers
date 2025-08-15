cmake_minimum_required(VERSION 3.10)
project(LinearSystemsSolver)

set(CMAKE_CXX_STANDARD 17)

# Собираем исполняемый файл
add_executable(linear-equation-solvers
    src/main.cpp
    src/thomas_algorithm.cpp
    src/simple_iteration.cpp
    src/matrix_io.cpp
)

# Подключаем заголовки
target_include_directories(linear-equation-solvers PRIVATE include)