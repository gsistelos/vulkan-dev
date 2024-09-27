#include "VulkanApp.hpp"

#include <iostream>

int main() {
    VulkanApp va;

    try {
        va.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
