#ifndef UTILS_HPP
#define UTILS_HPP

#include <vulkan/vulkan_core.h>

bool isDeviceSuitable(VkPhysicalDevice device);
void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);

#endif // UTILS_HPP
