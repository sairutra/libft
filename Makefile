# This is the $(NAME) macro that is equivalent to the 
# libft.a file.

NAME = libft.a

LIB_DIR = libft

PRINT_DIR = ft_printf

PRINT_A = libftprintf.a

GNL_DIR = get_next_line

GNL_A = get_next_line.a

# This all is rule that is dependent on $(NAME) rule
# because it is the first command in the makefile, it will be 
# triggered when we call "make" in the terminal

all: $(NAME)

# This is a rule that is called $(NAME), which is dependent on
# $(OBJS), which once it's updates, fires the ar command to 
# (r)eplace files in archive that been changed, (c) create new 
# files if they did not exist yet, and reindex(s) the archive
# to make it easier to locate files

$(NAME): $(PRINT_DIR)/$(PRINT_A) $(GNL_DIR)/$(GNL_A) $(LIB_DIR)/$(NAME) 

$(PRINT_DIR)/$(PRINT_A): 
	@$(MAKE) -C $(PRINT_DIR) all
	ar rcs $(NAME) $(PRINT_DIR)/*.o

$(GNL_DIR)/$(GNL_A):
	@$(MAKE) -C $(GNL_DIR) all
	ar rcs $(NAME) $(GNL_DIR)/*.o

$(LIB_DIR)/$(NAME):
	@$(MAKE) -C $(LIB_DIR) all
	ar rcs $(NAME) $(LIB_DIR)/*.o

# all command is dependent on .o files existing, so this rule
# will make sure to (re)create them if neccessary. This rule is a 
# a pattern rule ‘%.o : %.c’ that says how to make any file stem.o 
# from another file stem.c. It uses the automatic variable $@ for 
# source file which is %.o and $< for each target file which is %.c
# and it will apply this rule for each case. -c is to make object files
# and -o to then name those .o files.

clean:
	@$(MAKE) -C $(PRINT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJS)
	rm -f $(B-OBJS)

# This rule has a target which is clean
# This will make sure clean is up to date and 
# execute it's commands before, it cleans the 
# $(NAME) macro

fclean: clean
	@$(MAKE) -C $(PRINT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

# This rule has a target which is fclean
# This will make sure fclean is up to date and 
# execute it's commands before. Then it will do the
# same with all.

re: fclean all

bonus: $(B-OBJS)
	ar rcs $(NAME) $(B-OBJS)