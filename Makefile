NAME = libft.a

LIB_DIR = libft

PRINT_DIR = ft_printf

PRINT_A = libftprintf.a

GNL_DIR = get_next_line

GNL_A = get_next_line.a

all: $(NAME)

$(NAME): $(PRINT_DIR)/$(PRINT_A) $(GNL_DIR)/$(GNL_A) $(LIB_DIR)/$(NAME) 

$(PRINT_DIR)/$(PRINT_A): 
	@$(MAKE) -C $(PRINT_DIR) all
	@ar rcs $(NAME) $(PRINT_DIR)/*.o

$(GNL_DIR)/$(GNL_A):
	@$(MAKE) -C $(GNL_DIR) all
	@ar rcs $(NAME) $(GNL_DIR)/*.o

$(LIB_DIR)/$(NAME):
	@$(MAKE) -C $(LIB_DIR) all
	@ar rcs $(NAME) $(LIB_DIR)/*.o

clean:
	@$(MAKE) -C $(PRINT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(LIB_DIR) clean
	@rm -f $(OBJS)
	@rm -f $(B-OBJS)

fclean: clean
	@$(MAKE) -C $(PRINT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(MAKE) -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all

bonus: $(B-OBJS)
	ar rcs $(NAME) $(B-OBJS)