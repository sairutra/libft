LIB_DIR = src/libft
PRINT_DIR = src/ft_printf
GNL_DIR = src/get_next_line

PRINT_A = libftprintf.a
GNL_A = get_next_line.a
NAME = libft.a


all: directory $(NAME)


directory:
	mkdir -p lib
	
$(NAME): $(PRINT_DIR)/$(PRINT_A) $(GNL_DIR)/$(GNL_A) $(LIB_DIR)/$(NAME) 
	cp $(PRINT_DIR)/lib/$(PRINT_A) lib
	cp $(GNL_DIR)/lib/$(GNL_A) lib
	cp $(LIB_DIR)/lib/$(NAME) lib
	ar -x lib/$(PRINT_A)
	mv *.o lib/
	ar -x lib/$(GNL_A)
	mv *.o lib/
	rm get_next_line.a
	@ar rcs lib/$(NAME) lib/*.o
	rm lib/*.o
	rm lib/$(PRINT_A)
	@rm lib/$(GNL_A)

$(PRINT_DIR)/$(PRINT_A): 
	@$(MAKE) -C $(PRINT_DIR) all

$(GNL_DIR)/$(GNL_A):
	@$(MAKE) -C $(GNL_DIR) all

$(LIB_DIR)/$(NAME):
	@$(MAKE) -C $(LIB_DIR) all

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
	rm -rf lib 

re: fclean all

bonus: $(B-OBJS)
	ar rcs $(NAME) $(B-OBJS)