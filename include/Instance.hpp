#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#ifdef NDEBUG
#define ENABLE_VALIDATION_LAYERS false
#else
#define ENABLE_VALIDATION_LAYERS true
#endif

#include "DebugMessenger.hpp"
#include "PhysicalDevice.hpp"
#include <vector>

const std::vector<const char *> VALIDATION_LAYERS = {
    "VK_LAYER_KHRONOS_validation",
};

class Instance {
  public:
    Instance(void);
    ~Instance();

  private:
    VkInstance instance;

    DebugMessenger debugMessenger;
    PhysicalDevice physicalDevice;

    const char *APPLICATION_NAME = "Vulkan Dev";
    const char *ENGINE_NAME = "No Engine";

    void createInstance(void);
    void pickPhysicalDevice(void);
};

#endif // INSTANCE_HPP
