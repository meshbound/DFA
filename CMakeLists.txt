cmake_minimum_required(VERSION 3.24.2)

project(CMakeTest)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_subdirectory(./vendor/wxWidgets-3.2.2.1)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(test ${SOURCES})

target_link_libraries(test wx::net wx::core wx::base)
