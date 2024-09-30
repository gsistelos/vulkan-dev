#ifndef WINDOW_HPP
#define WINDOW_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class Window {
  public:
    Window(void);
    ~Window();

    bool shouldClose(void) const;

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

  private:
    GLFWwindow *window;

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 800;

    const char *TITLE = "Vulkan";
};

#endif // WINDOW_HPP
