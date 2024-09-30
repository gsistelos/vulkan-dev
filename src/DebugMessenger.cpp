#include "DebugMessenger.hpp"

#include "utils.hpp"
#include <stdexcept>

static VkResult createDebugUtilsMessengerEXT(
    VkInstance &instance,
    const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
    const VkAllocationCallbacks *pAllocator,
    VkDebugUtilsMessengerEXT *pDebugMessenger) {

    auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
        instance, "vkCreateDebugUtilsMessengerEXT");
    if (!func) {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
}

static void destroyDebugUtilsMessengerEXT(
    VkInstance &instance,
    VkDebugUtilsMessengerEXT &debugMessenger,
    const VkAllocationCallbacks *pAllocator) {

    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
        instance, "vkDestroyDebugUtilsMessengerEXT");
    if (func) {
        func(instance, debugMessenger, pAllocator);
    }
}

void DebugMessenger::setup(VkInstance &instance) {
    VkDebugUtilsMessengerCreateInfoEXT createInfo{};
    populateDebugMessengerCreateInfo(createInfo);

    if (createDebugUtilsMessengerEXT(
            instance, &createInfo, nullptr, &debugMessenger) != VK_SUCCESS) {
        throw std::runtime_error("failed to create debug messenger");
    }
}

void DebugMessenger::destroy(VkInstance &instance) {
    destroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
}
