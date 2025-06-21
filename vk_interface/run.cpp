#include "vk.hpp"

void Vulkan::run( vk_param& param ) {

#ifdef VK_DEBUG_notifications_
	std::clog << VK_NOTIFY_COLOR << "start vulkan.run()" << VK_RESET_COLOR << "\n";
#endif
	try {
		createInstance( param );
		createSurface( param.window );
		pickPhysicalDevice();
		createLogicalDevice();

#ifdef VK_DEBUG_notifications_
		std::clog << VK_NOTIFY_COLOR << "custom end vulkan.run()" << VK_RESET_COLOR "\n";
#endif

	} catch( vk::su::custom_exception& ex ) {

#ifdef VK_DEBUG_info_
		std::clog << VK_INFO_COLOR << "custom param error. started with default parameters...\n" << VK_RESET_COLOR;
#endif
#ifdef VK_DEBUG_L1_
		std::clog << VK_ERROR_COLOR << "error in Vulkan::run()\n\tvk::su::custom_exception\n\ttype: " << ex.getType() << "\n\tmsg: " << ex.getMsg() << "\n" << VK_RESET_COLOR;
#endif

		param.enableValidationLayers = true;
		param.validationLayers = { "VK_LAYER_KHRONOS_validation" };

		createInstance( param );
		createSurface( param.window );
		pickPhysicalDevice();
		createLogicalDevice();

#ifdef VK_DEBUG_notifications_
		std::clog << VK_NOTIFY_COLOR << "default end vulkan.run()\n" << VK_RESET_COLOR;
#endif

	} catch( const std::exception& ex ) {
		throw std::runtime_error( ex.what() );
	} catch(...) {
		throw std::runtime_error("unknown error.\n");
	}
}
