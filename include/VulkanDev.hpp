#ifndef VULKAN_DEV_HPP
#define VULKAN_DEV_HPP

#ifdef NDEBUG
#define ENABLE_VALIDATION_LAYERS false
#else
#define ENABLE_VALIDATION_LAYERS true
#endif

#include <vector>

const std::vector<const char *> VALIDATION_LAYERS = {
    "VK_LAYER_KHRONOS_validation",
};

#endif // VULKAN_DEV_HPP
