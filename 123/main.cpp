#include <vk_interface/vk.hpp>

int main( const uint16_t argc, const char* argv[] ) {
#ifndef NDEBUG
	std::cout << ITALIC << "\033[34m" << "The September 21st Incident of Gigi Murin." << VK_RESET_COLOR << "\n" << std::flush;
#endif
//	std::cout << "\e[48;5;235m" << "                     \n" << "     Hi Friend!!     " << "\n                     " << RESET "\n";
	try {
/*
		std::cout << RESET BLACK << "▇▇" << RESET;
		std::cout << RED << "▇▇" << RESET;
		std::cout << GREEN << "▇▇" << RESET;
		std::cout << YELLOW << "▇▇" << RESET;
		std::cout << BLUE << "▇▇" << RESET;
		std::cout << MAGNETA << "▇▇" << RESET;
		std::cout << CYAN << "▇▇" << RESET;
		std::cout << WHITE << "▇▇" << RESET << "\n";
*/
// ██
		//throw std::runtime_error("the error.");
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        	GLFWwindow* window = glfwCreateWindow( 1920, 1080, "No title", nullptr, nullptr );//	1920x810 or 1920x960
		if ( window == nullptr ) {
			glfwTerminate();
			throw std::runtime_error("failed to create glfw window.");
		}

		Vulkan vulkan;

		vk_param param;
		param.enableValidationLayers = true;
		param.validationLayers = { "VK_LAYER_KHRONOS_validation" };
		param.window = window;

		vulkan.run( param );

		glfwDestroyWindow( window );
		vulkan.terminate();
		glfwTerminate();

	} catch( vk::su::custom_exception& ex ) {
		std::cerr << VK_FATAL_COLOR << "su::custom_exception\n" << "\ttype: " << ex.getType() << "\n\t" << ex.getMsg() << VK_RESET_COLOR << "\n";
		exit( -1 );

	} catch( const std::exception& ex ) {
		std::cerr << VK_FATAL_COLOR << "std::exception: " << ex.what() << VK_RESET_COLOR << "\n";
		exit( -1 );

	} catch( ... ) {
		std::cerr << VK_FATAL_COLOR << "unknown exception." << VK_RESET_COLOR "\n";
		exit( -1 );
	}

	return 0;
}
