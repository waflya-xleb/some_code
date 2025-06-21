cmake_minimum_required ( VERSION 3.31.6 )

project( decoder
	VERSION 0.0.0
	LANGUAGES C )

add_executable( ${PROJECT_NAME} decoder.c )
