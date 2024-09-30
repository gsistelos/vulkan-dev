#include "VulkanApp.hpp"

void VulkanApp::run(void) {
    while (!window.shouldClose()) {
        glfwPollEvents();
    }
}
