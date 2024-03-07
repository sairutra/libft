LIBFT = ../../../libft

LIBFT_A = libft.a

WELCOME = libft_tester_welcome.c

TESTER = libft_tester.c

TEST_DIR = libft_tests

TESTS = ft_atoi_tests.c

NORMINETTE = libft_norminette.c

all: test

.SILENT:

test:
	@$(MAKE) -C $(LIBFT) all
	cp $(LIBFT)/$(LIBFT_A) ./
	@$(MAKE) -C $(LIBFT) fclean
	cc -Wall -Werror -Wextra $(WELCOME) && ./a.out
	rm a.out
	cc -Wall -Werror -Wextra $(NORMINETTE) && ./a.out
	rm a.out
	mkdir -p logs
	cc -Wall -Werror -Wextra -lbsd $(TESTER) $(TEST_DIR)/*.c $(LIBFT_A) && ./a.out
	rm a.out


fclean:
	rm -rf $(LIBFT_A)
	rm -rf logs