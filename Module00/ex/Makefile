# Project Name
NAME := ex00

# Compiler
CXX := c++

# Source files
SRCS := Account.cpp \
	Bank.cpp \
	main.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Compilation flags
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Phony targets are ones that do not create a file named after the target name.
.PHONY: all clean fclean re
