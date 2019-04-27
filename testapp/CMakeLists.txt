# CMake for test application 

cmake_minimum_required(VERSION 3.9)

find_library(ARGPARSER_LIBRARY argparser HINTS /usr/local/lib)

add_executable(testArgParser
                main.cpp)

target_include_directories(testArgParser PRIVATE ../argumentparser/include/
                                    SYSTEM INTERFACE ../argumentparser/include/)

target_compile_options(testArgParser PRIVATE -Werror -Wall -Wextra)

target_link_libraries(testArgParser ${ARGPARSER_LIBRARY})
