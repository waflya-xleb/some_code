#include "vkUtils.hpp"

namespace vk {
	namespace su {
		custom_exception::custom_exception( std::string type, std::string msg ) {
			this->type = type;
			this->msg = msg;
		}// constructor custom_exception

		std::string custom_exception::getType() {
			return type;
		}// getType()

		std::string custom_exception::getMsg() {
			return msg;
		}// getMsg()

		bool checkValidationLayerSupport( std::vector< const char* > requestedLayers, std::vector< const char* > &unavailableLayers ) {

			bool layerAvailable;

			uint32_t layerCount;
			vkEnumerateInstanceLayerProperties( &layerCount, nullptr );

			std::vector < VkLayerProperties > availableLayers( layerCount );
			vkEnumerateInstanceLayerProperties( &layerCount, availableLayers.data() );

			for ( const char* layerName : requestedLayers ) {
				layerAvailable = false;

				for ( const VkLayerProperties& layerProperties : availableLayers ) {

					if ( strcmp( layerName, layerProperties.layerName ) == 0 ) {
						layerAvailable = true;
						break;
					}
				}

				if ( !layerAvailable ) {
					unavailableLayers.push_back( layerName );
				}
			}

			return unavailableLayers.size() == 0;
		}// checkValidationLayerSupport()
	}// su namespace
}// vk namespace
