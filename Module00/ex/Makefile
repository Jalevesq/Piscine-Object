RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m
RESET := \033[0m
BOLD := \033[1m

# Project Name
NAME := BankAccount

# Compiler
CXX := c++

# Path Prefix
PATH_PREFIX := ex00/
OBJS_PREFIX := ex00/objs/

# Source files with prefix
SRC_FILES := Account.cpp Bank.cpp main.cpp
SRCS := $(addprefix $(PATH_PREFIX),$(SRC_FILES))

# Object files with prefix
OBJS := $(SRCS:$(PATH_PREFIX)%.cpp=$(OBJS_PREFIX)%.o)

# Compilation flags
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Total number of source files
TOTAL_FILES := $(words $(SRC_FILES))

# Counter to keep track of the number of compiled files
COMPILED_COUNT := 0

# Function to update and print the compile progress
define update_compile_progress
$(eval COMPILED_COUNT=$(shell echo $$(($(COMPILED_COUNT)+1))))
@printf "\033[KCompiling... [$(COMPILED_COUNT)/$(TOTAL_FILES)] - $(1)\r"
endef

all: $(OBJS_PREFIX) $(NAME)
	@if [ $(COMPILED_COUNT) -gt 0 ]; then \
		printf "\033[K"; \
		echo "$(GREEN)$(BOLD)Compilation finished [$(TOTAL_FILES)/$(TOTAL_FILES)]$(RESET)"; \
	fi

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $(NAME)

$(OBJS_PREFIX):
	@mkdir -p $(OBJS_PREFIX)

$(OBJS_PREFIX)%.o: $(PATH_PREFIX)%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	$(call update_compile_progress, $<)

clean:
	@printf "$(YELLOW)Cleaning up object files...$(RESET)"
	@rm -rf $(OBJS_PREFIX)
	@printf "\r\033[K$(GREEN)Done cleaning up object files$(RESET)\n"


fclean: clean
	@printf "$(RED)Removing executable $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@printf "\r\033[K$(GREEN)Done removing executable $(NAME)$(RESET)\n"

re:
	@echo "$(MAGENTA)Recompiling $(NAME)...$(RESET)"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
