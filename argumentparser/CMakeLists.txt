# CMake for src folder

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
