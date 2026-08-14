-include mks/config.mk
-include mks/libs.mk

NAME = cub3D

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(GREEN)Building $(NAME).$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBFT_FLAGS) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	@echo "$(YELLOW)Cleaning objects.$(RESET)"
	@rm -f $(OBJS) $(DEPS)

fclean: clean
	@echo "$(YELLOW)Cleaning binaries.$(RESET)"
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT_DIR) > /dev/null 2> /dev/null
	@make clean -sC $(MLX_DIR) > /dev/null 2> /dev/null

re: fclean all

.DEFAULT_GOAL := all
.PHONY: all clean fclean re t

BLACK	= \e[1;30m
RED		= \e[1;31m
GREEN	= \e[92m
YELLOW	= \e[1;33m
BLUE	= \e[1;34m
PURPLE	= \e[1;35m
CYAN	= \e[1;36m
WHITE	= \e[1;37m
RESET	= \e[0m
