NAME		=	miniRT

include	src.mk

SRC			=	$(addprefix src/, $(SRC_FILES))
OBJ			=	$(SRC:.c=.o)

LIBS		=	ft mlx Xext X11 m

# **************************************************************************** #

LIB_DIR		=	lib/libft
MLX_DIR		=	lib/minilibx-linux

INC_DIR		=	include $(MLX_DIR) $(addsuffix /include, $(LIB_DIR))
SRC_DIR		=	src

LIB_PATHS	=	$(LIB_DIR) $(MLX_DIR)

# **************************************************************************** #

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(foreach path, $(INC_DIR), -I $(path))
LDFLAGS		=	$(foreach path, $(LIB_PATHS), -L $(path))
LIBFLAGS	=	$(foreach lib, $(LIBS), -l $(lib))

RM			=	rm -f
.c.o:
		@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
		@$(foreach path, $(LIB_PATHS), make -C $(path);)
		@$(CC) $(OBJ) $(LDFLAGS) $(LIBFLAGS) -o $@

all:	$(NAME)

clean:
		@$(RM) $(OBJ)
		@echo "Object files for $(NAME) removed."
		@$(foreach lib, $(LIB_PATHS), make -C $(lib) clean;)

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(NAME) removed."
		@$(foreach lib, $(LIB_DIR), make -C $(lib) fclean;)

re:	fclean all

check_leaks: re
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
		./miniRT scenes/sphere1.rt

.PHONY: all clean fclean re .c.o
