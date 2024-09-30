#include "VulkanApp.hpp"

#include <iostream>

int main(void) {
    try {
        VulkanApp va;
        va.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
