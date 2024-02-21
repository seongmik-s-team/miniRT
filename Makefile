# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 19:05:36 by jooahn            #+#    #+#              #
#    Updated: 2024/02/21 22:44:52 by seongmik         ###   ########.fr        #
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
SCENE_DIR					:=	scene
HIT_DIR						:=	hit
RAY_DIR						:=	ray
SPHERE_DIR					:=	sphere
CYLINDER_DIR				:=	cylinder
PLANE_DIR					:=	plane
LIGHT_DIR					:=	light
MR_MLX_DIR					:=	mlx
PARSER_DIR					:=	parser
ERROR_DIR					:=	error
DIRS						:=	$(LIB_DIR) $(MLX_DIR)
SRCS						:=	$(SRCS_DIR)/minirt.c \
								$(SRCS_DIR)/$(VECTOR_DIR)/vec_new.c \
								$(SRCS_DIR)/$(VECTOR_DIR)/vec_oper_basic.c \
								$(SRCS_DIR)/$(VECTOR_DIR)/vec_oper_linear_a.c \
								$(SRCS_DIR)/$(MR_MLX_DIR)/mr_mlx.c \
								$(SRCS_DIR)/$(MR_MLX_DIR)/hooks.c \
								$(SRCS_DIR)/$(COLOR_DIR)/color.c \
								$(SRCS_DIR)/$(RAY_DIR)/ray.c \
								$(SRCS_DIR)/$(LIGHT_DIR)/light.c \
								$(SRCS_DIR)/$(SCENE_DIR)/scene.c \
								$(SRCS_DIR)/$(HIT_DIR)/hit.c \
								$(SRCS_DIR)/$(OBJ_DIR)/object.c \
								$(SRCS_DIR)/$(PLANE_DIR)/plane.c \
								$(SRCS_DIR)/$(CYLINDER_DIR)/cylinder.c \
								$(SRCS_DIR)/$(SPHERE_DIR)/sphere.c \
								$(SRCS_DIR)/$(PARSER_DIR)/parser.c \
								$(SRCS_DIR)/$(PARSER_DIR)/add_to_scene.c \
								$(SRCS_DIR)/$(PARSER_DIR)/utils.c \
								$(SRCS_DIR)/$(PARSER_DIR)/utils2.c \
								$(SRCS_DIR)/$(ERROR_DIR)/error.c


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
