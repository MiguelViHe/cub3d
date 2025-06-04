# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 10:02:29 by mvidal-h          #+#    #+#              #
#    Updated: 2025/06/04 16:49:38 by mvidal-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

CC			= cc
MKDIR		= mkdir -p
RM			= rm -rf
SUBMODULES	= submodules/
LIB			= submodules/lib

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

CFLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address -O3
IFLAGS		= -I$(INC_DIR) -I$(LIB)/$(INC_DIR)
LDFLAGS 	=  -L$(LIB) -lft -ldl -lglfw -pthread -lm

# Variables de fuentes y objetos
SRC_FILES	:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ_FILES := $(subst $(SRC_DIR),$(OBJ_DIR),$(SRC_FILES:.c=.o))


#all rule
all: $(NAME)

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)
	@echo -e "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@
	@printf "$(UP)$(CUT)"
	@echo -e "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

$(LIB):
	@make -sC $(SUBMODULES)

#compile the executable
$(NAME): $(LIB) $(OBJ_FILES)
	@echo -e "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ_FILES) $(LDFLAGS) -o $(NAME)
	@echo -e "$(GREEN)Finished [$(NAME)]$(RESET)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) $(OBJ_DIR); \
		echo -e "$(BLUE)Deleting all objects from $(NAME)...$(RESET)"; else \
		echo -e "No objects to remove from $(NAME)."; \
	fi;
	@make fclean -sC $(SUBMODULES)

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(RM) $(NAME); \
		echo -e "$(BLUE)Deleting $(NAME)...$(RESET)"; else \
		echo -e "No Executable to remove from $(NAME)."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re