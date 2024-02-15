NAME	=	miniRT

#
# SRCS and OBJS
#

SRCS	=	\
			src/main.c \
			src/utils/camera.c \
			src/utils/color.c \
			src/utils/point3.c \
			src/utils/ray.c \
			src/utils/vector3_1.c \
			src/utils/vector3_2.c \
			src/utils/viewport.c

OBJS = $(SRCS:%.c=%.o)

#
# Compiler and flags
#

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
INC		=	./includes
MLX		=	./mlx

#
# Rules
#

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I$(INC) -I$(MLX) $(SRCS) -o $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all
