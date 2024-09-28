#ifndef VULKAN_APP_HPP
#define VULKAN_APP_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600

#define TITLE "Vulkan"
#define APPLICATION_NAME "VulkanDev"
#define ENGINE_NAME "No Engine"

class VulkanApp {
  public:
    void run(void);

  private:
    GLFWwindow *window;
    VkInstance instance;

    void initWindow(void);
    void initVulkan(void);

    void mainLoop(void);

    void cleanup(void);

    void createInstance(void);
};

#endif // VULKAN_APP_HPP
