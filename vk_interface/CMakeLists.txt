cmake_minimum_required ( VERSION 3.31.7 )

include ( base-kit.cmake )
message ( DEBUG "${magenta}Starting compiling${blue} 'vk_interface'${yellow} library${rc}${gray}...${rc}" )


project(
	vk_interface
	VERSION ${ver}
	DESCRIPTION "123test."
	LANGUAGES ${supported_languages} )

#----------TEMPORARY----------#
find_package(Vulkan REQUIRED)
find_package(glfw3 3.4 REQUIRED)
#----------TEMPORARY-------------#


add_library( ${PROJECT_NAME} SHARED
	run.cpp			createInstance.cpp
	createSurface.cpp	pickPhysicalDevice.cpp
	createLogicalDevice.cpp	terminate.cpp
	vkUtils/vkUtils.cpp )
add_library( vk::${PROJECT_NAME} ALIAS ${PROJECT_NAME} )

set_target_properties( ${PROJECT_NAME} PROPERTIES
	PREFIX "libD_"
	OUTPUT_NAME "vk_interface"
	SUFFIX ".so.${ver}"
)
target_link_libraries( ${PROJECT_NAME} PRIVATE Vulkan::Vulkan )
target_link_libraries( ${PROJECT_NAME} PUBLIC glfw )

message ( DEBUG "${yellow}library ${blue}'vk_interface' ${rc}${gray}are ${rc}${magenta}created.${rc}" )

