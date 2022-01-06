NAME = miniRT

SRCS =	src/main.c \
		utils/get_next_line.c \
		utils/get_next_line_utils.c \
		parsing/parse.c \
		parsing/init.c \
		utils/utils.c \
		utils/utils1.c \
		utils/exits.c \
		utils/win_utils.c \
		parsing/parse_figure.c \
		parsing/parse_options.c \
		parsing/check.c \
		parsing/check2.c \
		grafics/window.c \
		src/miniRT.c \
		grafics/vector.c \
		grafics/RT.c \

INC	= 	libft/libft.h \
		minilibx/mlx.h \
		includes/get_next_line.h \
		includes/miniRT.h \

OBJS = $(SRCS:.c=.o)
OBJS_DIR = .obj

CC	= gcc
CFLAGS = -Wall -Wextra -Werror -o3
RM	= rm -rf

LD_FLAGS = -L libft -L minilibx
ACTIVATE_LIBS = ./libft/libft.a -lmlx ./minilibx/libmlx.a
FRAMEWORKS = -framework OpenGL -framework AppKit

.PHONY:			all clean fclean re

$(OBJS_DIR)/%.o:		%.c $(INC)
						@mkdir -p	$(OBJS_DIR) \
									$(OBJS_DIR)/src \
									$(OBJS_DIR)/utils \
									$(OBJS_DIR)/parsing \
									$(OBJS_DIR)/grafics
						$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(addprefix $(OBJS_DIR)/, $(OBJS))
				make -C ./minilibx/
				$(CC) $(CFLAGS) $(addprefix $(OBJS_DIR)/, $(OBJS)) $(FRAMEWORKS) $(ACTIVATE_LIBS) -o $(NAME)

clean:
				@$(RM) $(OBJS_DIR)
				@make clean -C ./minilibx
				@echo "\033[0;32mAll object files were deleted\033[0m"

fclean:			clean
				@$(RM) $(NAME)
				@echo "\033[0;32mExecutable file was deleted\033[0m"

re:				fclean $(NAME)