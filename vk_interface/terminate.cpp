#include "vk.hpp"

void Vulkan::terminate() {
	vkDestroyDevice( device, nullptr );
	vkDestroySurfaceKHR(instance, surface, nullptr);
	vkDestroyInstance(instance, nullptr);
	instance = VK_NULL_HANDLE;

#ifdef VK_DEBUG_notifications_
	std::clog << VK_NOTIFY_COLOR << "vk terminate\n" << VK_RESET_COLOR;
#endif
}
