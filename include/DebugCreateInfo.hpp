#ifndef DEBUG_MESSENGER_CREATE_INFO_HPP
#define DEBUG_MESSENGER_CREATE_INFO_HPP

#include <vulkan/vulkan_core.h>

class DebugCreateInfo {
  public:
    DebugCreateInfo(void);
    ~DebugCreateInfo();

    VkDebugUtilsMessengerCreateInfoEXT &getInfo(void);

  private:
    VkDebugUtilsMessengerCreateInfoEXT info;
};

#endif // DEBUG_MESSENGER_CREATE_INFO_HPP
