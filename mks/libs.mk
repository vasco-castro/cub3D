
# LIBFT linking and compilation flags
LIBFT_DIR		:= $(LIBS_DIR)libft/
LIBFT_REP		:= $(LIBFT_DIR).git
LIBFT			:= $(LIBFT_DIR)libft.a
CFLAGS			+= -I$(LIBFT_DIR) -I$(LIBFT_DIR)/$(INCS_DIR)
LDFLAGS			+= -L$(LIBFT_DIR) -lft

$(LIBFT_REP):
	@git submodule update --init --quiet $(LIBFT_DIR)

$(LIBFT): $(LIBFT_REP)
	@printf "$(GREEN)Building LIBFT.$(RESET)\n"
	@$(MAKE) -sC $(LIBFT_DIR) > /dev/null

UNAME			:= $(shell uname)

# MLX Linking and Compilation Flags
ifeq ($(UNAME),Linux)
	MLX_DIR		:= $(LIBS_DIR)minilibx-linux/
	CFLAGS		+= -I$(MLX_DIR) -I/usr/include -Imlx_linux -O3
	LDFLAGS		+= -L$(MLX_DIR) -L/usr/lib -lmlx -lXext -lX11 -lm -lz
else ifeq ($(UNAME),Darwin)
	MLX_DIR		:= $(LIBS_DIR)minilibx-opengl/
	CFLAGS		+= -I$(MLX_DIR) -DGL_SILENCE_DEPRECATION -Dmlx_destroy_display\(mlx_ptr\)=\(\(void\)\(mlx_ptr\),0\)
	LDFLAGS		+= -L$(MLX_DIR) -lmlx -Wl,-ObjC -framework OpenGL -framework AppKit -framework Cocoa
endif

MLX_REP		:= $(MLX_DIR).git
MLX			:= $(MLX_DIR)libmlx.a

$(MLX_REP):
	@git submodule update --init --quiet $(MLX_DIR)

$(MLX): $(MLX_REP)
	@printf "$(GREEN)Building MLX.$(RESET)\n"
	@$(MAKE) -sC $(MLX_DIR) > /dev/null
