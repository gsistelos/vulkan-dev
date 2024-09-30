#ifndef VULKAN_APP_HPP
#define VULKAN_APP_HPP

#include "Instance.hpp"
#include "Window.hpp"

class VulkanApp {
  public:
    void run(void);

  private:
    Window window;
    Instance instance;

    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    void initVulkan(void);

    void mainLoop(void);

    void cleanup(void);

    void createInstance(void);
    void setupDebugMessenger(void);
    void pickPhysicalDevice(void);
};

#endif // VULKAN_APP_HPP
