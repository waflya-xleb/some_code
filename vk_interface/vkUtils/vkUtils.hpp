#pragma once
#ifndef _VK_UTILS_
#define _VK_UTILS_

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "base_libs.hpp"
#include "colors.hpp"

namespace vk {
	namespace su {
		class custom_exception {
			public:
				custom_exception( std::string type, std::string msg );
				std::string getType();
				std::string getMsg();
			private:
				std::string type;
				std::string msg;
		};// custom_exception

		bool checkValidationLayerSupport( std::vector< const char* > requestedLayers, std::vector< const char* > &unavailableLayers );
	}// su namespace
}// vk namespace

#endif
