cmake_minimum_required(VERSION 3.24.2)

project(DFA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_SOURCE_DIR}/vendor)

if (NOT EXISTS ${EXTERNAL_INSTALL_LOCATION}/wxWidgets)
	execute_process(
		COMMAND git clone --recurse-submodules https://github.com/wxWidgets/wxWidgets ${EXTERNAL_INSTALL_LOCATION}/wxWidgets
	)
endif()

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(test ${SOURCES})

add_subdirectory(./vendor/wxWidgets)
target_link_libraries(test wx::net wx::core wx::base)
