#--------------------------------default flags---------------------------------#
NAME							=	miniRT
CC								=	cc
CFLAGS							=	-Wall -Wextra -Werror


#----------------------------------sources-------------------------------------#
INCLUDES 						:=	-I./includes
SRCS_DIR 						:=	srcs
SRCS							:=	$(SRCS_DIR)/main.c


#----------------------------------objects-------------------------------------#
OBJS 							:=	$(SRCS:.c=.o)


#-----------------------------------rules--------------------------------------#
all : $(NAME)

$(NAME) : $(OBJS)
	@rm -rf $@
	@echo "Compiling..."
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Done !"

%.o : %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "Done !"

clean :
	@echo "Cleaning Objects..."
	@rm -rf $(OBJS)
	@echo "Done !"

fclean : clean
	@echo "Cleaning..."
	@rm -rf $(NAME)
	@echo "Done !"

re : fclean all


#-----------------------------------phony--------------------------------------#
.PHONY: all clean fclean re
