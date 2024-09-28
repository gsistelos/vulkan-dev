#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <vulkan/vulkan_core.h>

bool checkValidationLayersSupport(
    const std::vector<const char *> validationLayers);

VkResult createDebugUtilsMessengerEXT(
    VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
    const VkAllocationCallbacks *pAllocator,
    VkDebugUtilsMessengerEXT *pDebugMessenger);

void destroyDebugUtilsMessengerEXT(VkInstance instance,
                                   VkDebugUtilsMessengerEXT debugMessenger,
                                   const VkAllocationCallbacks *pAllocator);

std::vector<const char *> getRequiredExtensions(void);

bool isDeviceSuitable(VkPhysicalDevice device);

void populateDebugMessengerCreateInfo(
    VkDebugUtilsMessengerCreateInfoEXT &createInfo);

#endif // UTILS_HPP
