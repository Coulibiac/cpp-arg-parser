cmake_minimum_required(VERSION 3.10)
project(argumentparser 
        LANGUAGES CXX
        VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(argumentparser)

add_subdirectory(testapp)
