
-include mks/config.mk mks/libs.mk

NAME := cub3D

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@printf "$(GREEN)Building $(NAME).$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "$(PURPLE)%s$(RESET)\n" "$$(cat banner.txt)"

clean:
	@printf "$(YELLOW)Cleaning objects.$(RESET)\n"
	@rm -f $(OBJS) $(DEPS)

fclean: clean
	@printf "$(YELLOW)Cleaning binaries.$(RESET)\n"
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT_DIR) > /dev/null 2> /dev/null
	@make clean -sC $(MLX_DIR) > /dev/null 2> /dev/null

re: fclean all

.DEFAULT_GOAL := all
.PHONY: all clean fclean re
