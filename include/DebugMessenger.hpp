#ifndef DEBUG_MESSENGER_HPP
#define DEBUG_MESSENGER_HPP

#include <vulkan/vulkan_core.h>

class DebugMessenger {
  public:
    void setup(const VkInstance &instance);
    void destroy(const VkInstance &instance);

  private:
    VkDebugUtilsMessengerEXT debugMessenger;
};

#endif // DEBUG_MESSENGER_HPP
