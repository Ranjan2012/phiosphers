# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmallawa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 17:49:14 by rmallawa          #+#    #+#              #
#    Updated: 2022/12/24 17:50:10 by rmallawa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# FLAGS
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

# COLORS
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

# EXECUTABLE
NAME = ./philo

# PATHS
SRC_PATH = ./src/
OBJ_PATH = ./obj/
UTILS_PATH = $(SRC_PATH)utils/

# SOURCES
SRC = $(SRC_PATH)main.c \
						$(SRC_PATH)exit.c $(SRC_PATH)init.c $(SRC_PATH)input.c $(SRC_PATH)reaper.c $(SRC_PATH)routine.c $(SRC_PATH)threads.c\
						$(UTILS_PATH)utils_one.c $(UTILS_PATH)utils_two.c

# OBJECTS
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

# RULES
all: $(NAME)
	@echo $(G)"        __     __ __                           __                     "$(X)
	@echo $(G)".-----.|  |--.|__|  |.-----.-----.-----.-----.|  |--.-----.----.-----."$(X)
	@echo $(G)"|  _  ||     ||  |  ||  _  |__ --|  _  |  _  ||     |  -__|   _|__ --|"$(X)
	@echo $(G)"|   __||__|__||__|__||_____|_____|_____|   __||__|__|_____|__| |_____|"$(X)
	@echo $(G)"|__|                                   |__|                           "$(X)
	@printf "\n\n"

$(OBJ_PATH)%.o :$(SRC_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo $(G)Finished [$@]$(X)

$(NAME): $(OBJ)
	@echo $(Y)Compiling [$(SRC)]
	@echo into [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@if [ -d "$(OBJ_PATH)" ]; then \
			rm -f -r $(OBJ_PATH); \
			echo $(R)Cleaning" "[$(OBJ) $(OBJ_PATH)]...$(X); else \
			echo "No objects to remove."; \
	fi;

fclean: clean
	@if [ -f "$(NAME)" ]; then \
			rm -f $(NAME); \
			echo $(R)Cleaning" "[$(NAME)]...$(X);else \
			echo "No executable to remove."; \
	fi;

re: fclean all

# ADDITIONAL RULES

norm:
	@echo $(G)Checking Norminette...$(X)
	@norminette | grep Error | egrep --color '.*Error!|$$' || true
	@echo $(G)Done$(X)

.PHONY: all, clean, fclean, re, norm

