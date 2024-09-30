#ifndef DEBUG_MESSENGER_HPP
#define DEBUG_MESSENGER_HPP

#include <vulkan/vulkan_core.h>

class DebugMessenger {
  public:
    void setup(VkInstance &instance);
    void destroy(VkInstance &instance);

  private:
    VkDebugUtilsMessengerEXT debugMessenger;
};

#endif // DEBUG_MESSENGER_HPP
