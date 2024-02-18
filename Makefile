#--------------------------------default flags---------------------------------#
NAME							=	miniRT
CC								=	cc
CFLAGS							=	-Wall -Wextra -Werror


#----------------------------------sources-------------------------------------#
INCLUDES 						:=	-I./includes
SRCS_DIR 						:=	srcs
LIB_DIR							:=	libft
SRCS							:=	$(SRCS_DIR)/main.c


#----------------------------------objects-------------------------------------#
OBJS 							:=	$(SRCS:.c=.o)


#-----------------------------------rules--------------------------------------#
all : $(NAME)

$(NAME) : $(OBJS)
	@rm -rf $@
	@echo "Compiling..."
	@$(MAKE) -C $(LIB_DIR);
	@cp $(LIB_DIR)/libft.a libft.a
	@$(CC) $(CFLAGS) -o $@ $^ libft.a
	@rm libft.a
	@echo "Done !"

%.o : %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "Done !"

clean :
	@echo "Cleaning Objects..."
	@$(MAKE) -C $(LIB_DIR) clean;
	@rm -rf libft.a
	@rm -rf $(OBJS)
	@echo "Done !"

fclean : clean
	@echo "Cleaning..."
	@$(MAKE) -C $(LIB_DIR) fclean;
	@rm -rf $(NAME)
	@echo "Done !"

re : fclean all


#-----------------------------------phony--------------------------------------#
.PHONY: all clean fclean re
