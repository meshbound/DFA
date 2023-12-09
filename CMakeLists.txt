cmake_minimum_required(VERSION 3.24.2)

project(DFA)

set(CMAKE_CXX_STANDARD 11)
set(wxBUILD_SHARED OFF)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_SOURCE_DIR}/vendor)

if (NOT EXISTS ${EXTERNAL_INSTALL_LOCATION}/wxWidgets)
	message(STATUS "Installing dependencies")
	execute_process(
		COMMAND git clone --recurse-submodules https://github.com/wxWidgets/wxWidgets ${EXTERNAL_INSTALL_LOCATION}/wxWidgets
	)
endif ()

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SOURCES "src/*.cpp")
if (WIN32)
	message(STATUS "WIN32 Build")
	add_executable(dfa WIN32 ${SOURCES})
else () 
	message(STATUS "Non-WIN32 Build")
	add_executable(dfa ${SOURCES})
endif ()

add_subdirectory(${EXTERNAL_INSTALL_LOCATION}/wxWidgets)
target_link_libraries(dfa wx::net wx::core wx::base X11)
