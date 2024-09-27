#ifndef VULKAN_APP_HPP
#define VULKAN_APP_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdint>

class VulkanApp {
  public:
    void run(void);

  private:
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    const char *TITLE = "Vulkan";

    GLFWwindow *window;

    const char *APP_NAME = "VulkanDev";
    const char *ENGINE_NAME = "No Engine";

    VkInstance instance;

    void initWindow(void);
    void initVulkan(void);

    void mainLoop(void);

    void cleanup(void);
};

#endif // VULKAN_APP_HPP
