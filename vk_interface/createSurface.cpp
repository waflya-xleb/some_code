#include "vk.hpp"

void Vulkan::createSurface( GLFWwindow* window ) {
	if ( glfwCreateWindowSurface( instance, window, nullptr, &surface ) != VK_SUCCESS ) {
		throw std::runtime_error("failed to create glfw surface.");
	}
#ifdef VK_DEBUG_notifications_
	std::clog << VK_SUCCESS_COLOR << "surface create success!\n" << VK_RESET_COLOR;
#endif
}
