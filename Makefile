NAME = miniRT

SRCS =

INC	= 	libft/libft.h \
		minilibx/mlx.h \

OBJS = $(SRCS:.c=.o)
OBJS_DIR = .obj

CC	= gcc
CFLAGS = -Wall -Wextra -Werror
RM	= rm -rf

LD_FLAGS = -L libft -L minilibx

.PHONY:			all clean fclean re

$(OBJS_DIR)/%.o:		%.c $(INC)
						@mkdir -p $(OBJS_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(addprefix $(OBJS_DIR)/, $(OBJS))
				$(CC) $(CFLAGS) $(addprefix $(OBJS_DIR)/, $(OBJS)) -framework OpenGL -framework AppKit ./minilibx/libmlx.a ./libft/libft.a -o $(NAME)

clean:
				@$(RM) $(OBJS_DIR)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)