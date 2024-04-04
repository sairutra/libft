LIB_DIR := ../../ft_printf/
LIB_ARC := libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf_tests.c ft_printftests_utils.c \
		ft_printf_welcome.c

OBJS = $(SRCS:.c=.o)

NAME = ft_printftests.a

NORMINETTE = norminette_tester/norminette.c

SRCDIR = ../src

SOURCES     := $(shell find $(SRCDIR) -type f -name "*.c")

.SILENT:

all: exe

exe: $(NAME) welcome logs norminette tests

exe_without_welcome: $(NAME) logs norminette tests

exe_welcome_lite: $(NAME) welcome_lite norminette logs tests

welcome_lite:
	cc -Wall -Werror -Wextra ft_printf_welcome_lite.c -o welcome_lite && ./welcome_lite 
	rm welcome_lite

welcome:
	cc -Wall -Werror -Wextra ft_printf_welcome.c -o welcome && ./welcome 
	rm welcome

logs:
	mkdir -p logs

norminette: 
	cc -Wall -Werror -Wextra $(NORMINETTE) && ./a.out $(SOURCES)
	rm a.out

tests:
	cc -Wall -Werror -Wextra ft_printftests.c ft_printftests.a ../lib/libftprintf.a && ./a.out
	rm a.out
	@$(MAKE) -s -C $(LIB_DIR) fclean

$(NAME): $(LIB_DIR)/$(LIB_ARC) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIB_DIR)/$(LIB_ARC): 
	@$(MAKE) -s -C $(LIB_DIR) all
	
 %.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@$(MAKE) -s -C $(LIB_DIR) clean
	rm -rf logs
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -s -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all