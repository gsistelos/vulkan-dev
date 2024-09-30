#include "Window.hpp"

#include <GLFW/glfw3.h>
#include <stdexcept>

Window::Window(void) {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, nullptr, nullptr);
    if (!window) {
        throw std::runtime_error("failed to create window");
    }
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Window::shouldClose(void) const { return glfwWindowShouldClose(window); }
