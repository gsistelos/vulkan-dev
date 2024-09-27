#include "VulkanApp.hpp"

#include "utils.hpp"

void VulkanApp::run(void) {
    initWindow();
    initVulkan();

    mainLoop();

    cleanup();
}

void VulkanApp::initWindow(void) {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, nullptr, nullptr);
}

void VulkanApp::initVulkan(void) {
    createInstance(APP_NAME, ENGINE_NAME, instance);
}

void VulkanApp::mainLoop(void) {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void VulkanApp::cleanup(void) {
    vkDestroyInstance(instance, nullptr);

    glfwDestroyWindow(window);
    glfwTerminate();
}
