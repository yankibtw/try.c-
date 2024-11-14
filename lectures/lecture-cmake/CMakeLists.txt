cmake_minimum_required(VERSION 3.10)
project(QuadraticSolver)


# Добавление исполняемого файла solution
add_executable(solution 
	src/solution.cpp
)


set_target_properties(
  solution PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)


# Определение типа точности (POINTTYPE)
set(POINTTYPE "short" CACHE STRING "Тип точности: short (float) или long (double)")
if(NOT POINTTYPE STREQUAL "short" AND NOT POINTTYPE STREQUAL "long")
    message(FATAL_ERROR "Неверный тип POINTTYPE. Используйте 'short' или 'long'.")
endif()


# Настройка опции точности для библиотеки solver
if(POINTTYPE STREQUAL "long")
    target_compile_definitions(solver PRIVATE USE_DOUBLE_PRECISION)
endif()


# Определение типа библиотеки (LIB_TYPE)
set(LIB_TYPE "STATIC" CACHE STRING "Тип библиотеки: STATIC или SHARED")
if(NOT LIB_TYPE STREQUAL "STATIC" AND NOT LIB_TYPE STREQUAL "SHARED")
    message(FATAL_ERROR "Неверный тип библиотеки LIB_TYPE. Используйте 'STATIC' или 'SHARED'.")
endif()


# Добавление библиотеки парсинга аргументов
add_library(parser ${LIB_TYPE} src/parser.cpp)
target_include_directories(parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


# Добавление библиотеки для решения квадратного уравнения
add_library(solver ${LIB_TYPE} src/solver.cpp)
target_include_directories(solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


# Связь библиотек с основным исполняемым файлом
target_link_libraries(solution PRIVATE parser solver)
