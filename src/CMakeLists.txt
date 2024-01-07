cmake_minimum_required(VERSION 3.22)

project(nippy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(include)

add_executable(nippy ${CMAKE_CURRENT_SOURCE_DIR}/main.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/lexer/tokenizer.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/tests/lexer_tests.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/file_functions_lib/file_functions.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/color_print_lib/color_print.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/lexer/variable_map.c
                     ${CMAKE_CURRENT_SOURCE_DIR}/lexer/ast.c)
