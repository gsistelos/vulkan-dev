# vulkan-dev

Learning how [Vulkan](https://www.vulkan.org/) works, following [Vulkan Tutorial](https://vulkan-tutorial.com/)

## Setup

See: [Vulkan development environment tutorial](https://vulkan-tutorial.com/Development_environment)

### TLDR

Debian:

```bash
sudo apt install vulkan-tools libvulkan-dev libglfw3-dev libglm-dev libxxf86vm-dev libxi-dev
```

For Debian, you will need to manually install [glslc](https://github.com/google/shaderc)

Arch:

```bash
sudo pacman -S --needed vulkan-devel glm shaderc libxi libxxf86vm
sudo pacman -S --needed glfw-wayland # or glfw-x11 for X11 users
```
