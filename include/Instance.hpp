#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <vulkan/vulkan_core.h>

class Instance {
  public:
    Instance(void);
    ~Instance();

    VkInstance &getInstance(void);

  private:
    VkInstance instance;

    const char *APPLICATION_NAME = "Vulkan Dev";
    const char *ENGINE_NAME = "No Engine";
};

#endif // INSTANCE_HPP
