cmake_minimum_required(VERSION 3.9)

message("MOCK DIR ${gmock_SOURCE_DIR}")
message("TEST DIR ${gtest_SOURCE_DIR}")

include_directories("${PROJECT_SOURCE_DIR}/argumentparser/include")
include_directories("${gtest_SOURCE_DIR}/include"
                    "${gmock_SOURCE_DIR}/include")

message("BINRAY DIR ${CMAKE_BINARY_DIR}")
link_directories("${CMAKE_BINARY_DIR}/lib")

add_executable(testArgParser 
                gtestMain.cpp
                BoolArgumentParser_Test.cpp
                ${PROJECT_SOURCE_DIR}/argumentparser/src/BoolArgumentParser.cpp
                )

target_link_libraries(testArgParser 
                        gtest
                        gmock
                        gmock_main
                        )
