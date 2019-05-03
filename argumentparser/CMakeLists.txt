# CMake for src folder

cmake_minimum_required(VERSION 3.9)

add_library(argparser SHARED
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ArgumentDriver.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/BoolArgumentParser.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/StringArgumentParser.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/IntArgumentParser.cpp
            )

install(TARGETS argparser
        LIBRARY DESTINATION lib)

target_include_directories(argparser PRIVATE include/
                                    SYSTEM INTERFACE include/)

target_compile_options(argparser PRIVATE -Werror -Wall -Wextra)

configure_file(${PROJECT_SOURCE_DIR}/argumentparser/cmake/cmake_helpers.cmake.in googletest-download/CMakeLists.txt)
message("${CMAKE_BINARY_DIR}")
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
                WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/argumentparser/googletest-download")

execute_process(COMMAND "${CMAKE_COMMAND}" --build .
                WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/argumentparser/googletest-download")

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

add_subdirectory(test)
