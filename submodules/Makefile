LIBFT := libft/libft.a
MLX42_DIR := MLX42
MLX42 := $(MLX42_DIR)/build/libmlx42.a
MLX42_INC := MLX42/include

LIB_DIR := lib/

all: $(LIBFT) $(MLX42)

$(LIBFT):
	@make -sC libft

$(MLX42):
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build && make -sC $(MLX42_DIR)/build -j4
	@cp MLX42/build/libmlx42.a $(LIB_DIR)
	@cp $(MLX42_INC)/*/*.h $(LIB_DIR)inc/

clean:
	@make fclean -sC libft/
	@rm -rf $(MLX42_DIR)/build

fclean: clean
	@rm -rf $(LIB_DIR)

re: fclean all

.SILENT: clean fclean 