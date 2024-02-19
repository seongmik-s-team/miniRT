# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 19:05:36 by jooahn            #+#    #+#              #
#    Updated: 2024/02/19 20:49:49 by seongmik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------default flags---------------------------------#
NAME						=	miniRT
CC							=	cc
CFLAGS						=	-Wall -Wextra -Werror


#----------------------------------sources-------------------------------------#
INCLUDES 					:=	-I./includes -I./libft/includes
SRCS_DIR 					:=	srcs
LIB_DIR						:=	libft
MLX_DIR						:=	mlx
OBJ_DIR						:=	object
VECTOR_DIR					:=	vector
COLOR_DIR					:=	color
MR_MLX_DIR					:=	mlx
DIRS						:=	$(LIB_DIR) $(MLX_DIR)
SRCS						:=	$(SRCS_DIR)/minirt.c \
								$(SRCS_DIR)/$(OBJ_DIR)/object.c \
								$(SRCS_DIR)/$(VECTOR_DIR)/vec_new.c \
								$(SRCS_DIR)/$(VECTOR_DIR)/vec_oper_basic.c \
								$(SRCS_DIR)/$(VECTOR_DIR)/vec_oper_linear_a.c \
								$(SRCS_DIR)/$(MR_MLX_DIR)/mr_mlx.c \
								$(SRCS_DIR)/$(MR_MLX_DIR)/hooks.c
								
MLX_FLAGS					:=	-Lmlx -lmlx -framework OpenGL -framework Appkit
LIBFT						:=	libft.a
MLX							:=	libmlx.dylib

#----------------------------------objects-------------------------------------#
OBJS 						:=	$(SRCS:.c=.o)


#-----------------------------------rules--------------------------------------#
all : $(NAME)

$(NAME) : $(OBJS)
	@rm -rf $@
	@echo "Compiling..."
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done
	@cp $(LIB_DIR)/$(LIBFT) $(LIBFT)
	@cp $(MLX_DIR)/$(MLX) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX_FLAGS)
	@rm $(LIBFT)
	@echo "Done !"

%.o : %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@
	@echo "Done !"

clean :
	@echo "Cleaning Objects..."
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done
	@rm -rf $(LIBFT)
	@rm -rf $(OBJS)
	@echo "Done !"

fclean : clean
	@echo "Cleaning..."
	@$(MAKE) -C $(LIB_DIR) fclean;
	@rm -rf $(NAME)
	@rm -rf $(MLX)
	@echo "Done !"

re : fclean all


#-----------------------------------phony--------------------------------------#
.PHONY: all clean fclean re
