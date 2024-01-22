cmake_minimum_required(VERSION 3.22)

project(nippy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(include)

add_executable(nippy ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/src/tokenizer.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/tests/lexer_tests.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/lib/file_functions_lib/src/file_functions.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/lib/color_printf_lib/src/color_print.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/src/variable_map.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/src/ast.c)
