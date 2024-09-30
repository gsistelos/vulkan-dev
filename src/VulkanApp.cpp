#include "VulkanApp.hpp"

#include "utils.hpp"
#include <stdexcept>

void VulkanApp::run(void) {
    initVulkan();

    mainLoop();

    cleanup();
}

void VulkanApp::initVulkan(void) {
    if (ENABLE_VALIDATION_LAYERS) {
        setupDebugMessenger();
    }
    pickPhysicalDevice();
}

void VulkanApp::mainLoop(void) {
    while (!window.shouldClose()) {
        glfwPollEvents();
    }
}

void VulkanApp::cleanup(void) {
    if (ENABLE_VALIDATION_LAYERS) {
        destroyDebugUtilsMessengerEXT(instance.getInstance(), debugMessenger,
                                      nullptr);
    }
}

void VulkanApp::createInstance(void) {}

void VulkanApp::setupDebugMessenger(void) {
    VkDebugUtilsMessengerCreateInfoEXT createInfo{};
    populateDebugMessengerCreateInfo(createInfo);

    if (createDebugUtilsMessengerEXT(instance.getInstance(), &createInfo,
                                     nullptr, &debugMessenger) != VK_SUCCESS) {
        throw std::runtime_error("failed to create debug messenger");
    }
}

void VulkanApp::pickPhysicalDevice(void) {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance.getInstance(), &deviceCount, nullptr);

    if (deviceCount == 0) {
        throw std::runtime_error("failed to find GPUs with Vulkan support");
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance.getInstance(), &deviceCount,
                               devices.data());

    for (const auto &device : devices) {
        if (isDeviceSuitable(device)) {
            physicalDevice = device;
            break;
        }
    }

    if (physicalDevice == VK_NULL_HANDLE) {
        throw std::runtime_error("failed to find a suitable GPU!");
    }
}
