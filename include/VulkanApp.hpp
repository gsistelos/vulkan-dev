#ifndef VULKAN_APP_HPP
#define VULKAN_APP_HPP

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define WINDOW_TITLE "Vulkan"

#define APPLICATION_NAME "VulkanDev"
#define ENGINE_NAME "No Engine"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class VulkanApp {
  public:
    void run(void);

  private:
    GLFWwindow *window;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    void initWindow(void);
    void initVulkan(void);

    void mainLoop(void);

    void cleanup(void);

    void createInstance(void);
    void setupDebugMessenger(void);
    void pickPhysicalDevice(void);
};

#endif // VULKAN_APP_HPP
