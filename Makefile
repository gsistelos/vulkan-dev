TARGET = VulkanDev

SRC = $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -Iinclude -std=c++17

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

RM = rm -f


.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(TARGET)

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: fclean
fclean:
	$(RM) $(OBJ) $(TARGET)

.PHONY: re
re: fclean all
