NAME	=	miniRT

#
# SRCS and OBJS
#

SRCS	=	\
			src/main.c
			src/utils/vector3_1.c
			src/utils/vector3_2.c
			src/utils/ray.c

OBJS = $(SRCS:%.c=%.o)

#
# Compiler and flags
#

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
INC		=	./includes

#
# Rules
#

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(INC) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all
