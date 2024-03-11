include ../../libft/sources.mk

LIBFT = ../../../libft

LIBFT_A = libft.a

WELCOME = libft_tester_welcome.c

TESTER = libft_tester.c

TEST_DIR = libft_tests

TESTS = ft_atoi_tests.c

NORMINETTE = ../../libft/norminette_tester/norminette.c

all: test

.SILENT:

test: libft logs welcome norminette tests


tests:
	cc -Wall -Werror -Wextra $(TESTER) $(TEST_DIR)/*.c $(LIBFT_A) -lbsd && ./a.out
	rm a.out

norminette:
	cc -Wall -Werror -Wextra $(NORMINETTE) && ./a.out $(SOURCES)
	rm a.out

welcome:
	cc -Wall -Werror -Wextra $(WELCOME) && ./a.out
	rm a.out

logs:
	mkdir -p logs

libft:
	@$(MAKE) -C $(LIBFT) all
	cp $(LIBFT)/$(LIBFT_A) ./
	@$(MAKE) -C $(LIBFT) fclean

fclean:
	rm -rf $(LIBFT_A)
	rm -rf logs