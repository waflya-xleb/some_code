cmake_minimum_required ( VERSION 3.31.6 )

set ( CMAKE_CXX_STANDARD 23 )

project( test123
	VERSION 0.0.0
	LANGUAGES CXX )

add_subdirectory(../vk_interface vk_interface)

include_directories(../)

add_executable( ${PROJECT_NAME} main.cpp )
target_link_libraries( ${PROJECT_NAME} vk::vk_interface )
