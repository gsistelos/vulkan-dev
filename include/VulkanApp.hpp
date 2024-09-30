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

    void mainLoop(void);
};

#endif // VULKAN_APP_HPP
