# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 10:02:29 by mvidal-h          #+#    #+#              #
#    Updated: 2025/05/30 12:10:22 by mvidal-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

CC			=	cc
MKDIR		= mkdir -p

# directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

CFLAGS		=	-Wall -Werror -Wextra
IFLAGS		= -I$(INC_DIR)
LDFLAGS 	=  -lm

# Variables de fuentes y objetos
SRC_FILES	:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ_FILES	:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

#all rule
all: $(NAME)

#compile the executable
$(NAME): $(OBJ_FILES)
	@echo -e "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ_FILES) $(LDFLAGS) -o $(NAME)
	@echo -e "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)
	@echo -e "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@
	@printf "$(UP)$(CUT)"
	@echo -e "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo -e "$(BLUE)Deleting all objects from /$(EXERCISE)...$(RESET)"; else \
	echo -e "No objects to remove from /$(EXERCISE)."; \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo -e "$(BLUE)Deleting $(NAME) from $(EXERCISE)...$(RESET)"; else \
	echo -e "No Executable to remove from $(EXERCISE)."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re