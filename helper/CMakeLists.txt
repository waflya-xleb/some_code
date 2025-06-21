cmake_minimum_required ( VERSION 3.31.7 )
include ( base-kit.cmake )

message ( DEBUG "${magenta}Starting compiling${blue} 'imagine a very cool project name'${yellow} library${rc}${gray}...${rc}" )

project( program_starter
	VERSION ${ver}
	LANGUAGES ${supported_languages} )

add_executable( ${PROJECT_NAME} program_starter.c shm_system/utils.c ipc_system/decoder.c )

add_executable( err_manager err_man/error_manager.c shm_system/utils.c ipc_system/decoder.c )


add_library( theLib SHARED theLib/theLib.cpp )
add_library( thetheLib SHARED thetheLib/thetheLib.cpp )

add_executable( program program_test/program.cpp )
add_executable( program_2 program_test/program_2.cpp )

#target_link_libraries( program_2 theLib )
