#include "VulkanApp.hpp"

#include "VulkanDev.hpp"
#include "utils.hpp"
#include <stdexcept>

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

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE,
                              nullptr, nullptr);
    if (!window) {
        throw std::runtime_error("failed to create window");
    }
}

void VulkanApp::initVulkan(void) {
    createInstance();
    if (ENABLE_VALIDATION_LAYERS) {
        setupDebugMessenger();
    }
}

void VulkanApp::mainLoop(void) {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void VulkanApp::cleanup(void) {
    if (ENABLE_VALIDATION_LAYERS) {
        destroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
    }

    vkDestroyInstance(instance, nullptr);

    glfwDestroyWindow(window);
    glfwTerminate();
}

void VulkanApp::createInstance(void) {
    if (ENABLE_VALIDATION_LAYERS &&
        !checkValidationLayersSupport(VALIDATION_LAYERS)) {
        throw std::runtime_error(
            "validation layers requested but not available");
    }

    VkApplicationInfo appInfo{};

    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = APPLICATION_NAME;
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = ENGINE_NAME;
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};

    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    auto extensions = getRequiredExtensions();

    createInfo.enabledExtensionCount = extensions.size();
    createInfo.ppEnabledExtensionNames = extensions.data();

    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};

    if (ENABLE_VALIDATION_LAYERS) {
        createInfo.enabledLayerCount = VALIDATION_LAYERS.size();
        createInfo.ppEnabledLayerNames = VALIDATION_LAYERS.data();

        populateDebugMessengerCreateInfo(debugCreateInfo);
        createInfo.pNext = &debugCreateInfo;
    } else {
        createInfo.enabledLayerCount = 0;
        createInfo.pNext = nullptr;
    }

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance");
    }
}

void VulkanApp::setupDebugMessenger(void) {
    VkDebugUtilsMessengerCreateInfoEXT createInfo{};
    populateDebugMessengerCreateInfo(createInfo);

    if (createDebugUtilsMessengerEXT(instance, &createInfo, nullptr,
                                     &debugMessenger) != VK_SUCCESS) {
        throw std::runtime_error("failed to create debug messenger");
    }
}
