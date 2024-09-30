#ifndef PHYSICAL_DEVICE_HPP
#define PHYSICAL_DEVICE_HPP

#include <vulkan/vulkan_core.h>

class PhysicalDevice {
  public:
    void pick(VkInstance &instance);

  private:
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
};

#endif // PHYSICAL_DEVICE_HPP
