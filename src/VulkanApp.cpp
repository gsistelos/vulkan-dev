#include "VulkanApp.hpp"

#include "VulkanDev.hpp"
#include "utils.hpp"
#include <stdexcept>

void VulkanApp::run(void) {
    initVulkan();

    mainLoop();

    cleanup();
}

void VulkanApp::initVulkan(void) {
    createInstance();
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
        destroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
    }

    vkDestroyInstance(instance, nullptr);
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

void VulkanApp::pickPhysicalDevice(void) {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

    if (deviceCount == 0) {
        throw std::runtime_error("failed to find GPUs with Vulkan support");
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

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
