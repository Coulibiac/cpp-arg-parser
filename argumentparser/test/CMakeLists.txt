cmake_minimum_required(VERSION 3.9)

find_package(Threads REQUIRED)

include(ExternalProject)

ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    INSTALL_COMMAND ""
    )

ExternalProject_Get_Property(gtest source_dir binary_dir)
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

set_target_properties(libgtest PROPERTIES 
    "IMPORTED_LOCATION" "${binary_dir}/lib/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    )

include_directories("${source_dir}/googletest/include
                     ${source_dir}/googlemock/include")

find_library(LIBGMOCK gmock HINTS "${binary_dir}/lib")
find_library(LIBGMOCKMAIN gmock_main HINTS "${binary_dir}/lib")

include_directories("${PROJECT_SOURCE_DIR}/argumentparser/include")

add_executable(testArgParser 
                gtestMain.cpp
                BoolArgumentParser_Test.cpp
                ${PROJECT_SOURCE_DIR}/argumentparser/src/BoolArgumentParser.cpp
                )

target_link_libraries(testArgParser 
                        libgtest
                        ${LIBGMOCK}
                        ${LIBGMOCKMAIN}
                        )
