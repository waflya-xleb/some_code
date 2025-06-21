#pragma once
#ifndef _VK_HPP_
#define _VK_HPP_

#include "vkUtils/vkUtils.hpp"

#define VK_DEBUG_notifications_
#define VK_DEBUG_info_
#define VK_DEBUG_L1_
#define VK_DEBUG_L2_

typedef struct {
	std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
	GLFWwindow* window;
	bool enableValidationLayers = true;
} vk_param;

//"VK_LAYER_LUNARG_parameter_validation",
//"VK_LAYER_LUNARG_device_limits",
//"VK_LAYER_LUNARG_object_tracker",
//"VK_LAYER_KHRONOS_validation"
//"VK_LAYER_LUNARG_api_dump"
//"VK_LAYER_LUNARG_monitor"

class Vulkan {
	public:
		void run( vk_param& param );
		void terminate();

	private:
		VkInstance instance = VK_NULL_HANDLE;
		VkSurfaceKHR surface;
		VkPhysicalDevice physicalDevice;
		VkDevice device;
		VkQueue queue;

		void createInstance( const vk_param& param );
		void createSurface( GLFWwindow* window );
		void pickPhysicalDevice();
		void createLogicalDevice();

};

#endif
