#include "vk.hpp"

void Vulkan::createInstance( const vk_param& param ) {
	VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "vk_interface";
        appInfo.applicationVersion = VK_MAKE_VERSION( 0, 0, 1 );
        appInfo.pEngineName = nullptr;
        appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_4;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

 	uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions( &glfwExtensionCount );

	std::vector< const char* > extensions( glfwExtensions, glfwExtensions + glfwExtensionCount );

	//extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

#ifdef VK_DEBUG_info_
	std::clog << VK_INFO_COLOR << "Vulkan extensions: \n" << VK_RESET_COLOR;
	for ( uint32_t i = 0; i < extensions.size(); i++) {
		std::clog << MAGNETA "\t" << extensions[i] << VK_RESET_COLOR << "\n";
	}
#endif
        createInfo.enabledExtensionCount = static_cast<uint32_t>( extensions.size() );
        createInfo.ppEnabledExtensionNames = extensions.data();

	if ( param.enableValidationLayers ) {
#ifdef VK_DEBUG_info_
		std::clog << VK_WARN_COLOR << "list of requested validation layers:\n\t" << MAGNETA;
		for ( const char* layerName : param.validationLayers ) {
			std::clog << layerName << "\n\t";
		}
		std::clog << "\n" << VK_RESET_COLOR;
#endif
		std::vector < const char* > unavailableLayers;
		if ( !vk::su::checkValidationLayerSupport( param.validationLayers, unavailableLayers ) ) {

			std::clog << VK_WARN_COLOR << "requested validation layers are not available:\n\t" << MAGNETA;
			for ( const char* layer : unavailableLayers ) {
				std::clog << layer << "\n\t";
			}
			std::clog << "\n" << VK_RESET_COLOR;
			throw vk::su::custom_exception( "instance error", "validationLayers not present." );
			//throw std::runtime_error("requested layer unavailable");
		}

		createInfo.enabledLayerCount = static_cast<uint32_t>( param.validationLayers.size() );
        	createInfo.ppEnabledLayerNames = param.validationLayers.data();
	} else {
		createInfo.enabledLayerCount = 0;
	}

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		//throw vk_su::custom_exception( "create instance error", "failed to create instance." );
		throw std::runtime_error("failed to create instance");
        }
#ifdef VK_DEBUG_notifications_
	std::clog << VK_SUCCESS_COLOR << "create instance success!\n" << VK_RESET_COLOR;
#endif
}
