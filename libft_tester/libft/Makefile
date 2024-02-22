LIBFT = ../../../libft

LIBFT_A = libft.a

WELCOME = libft_tester_welcome.c

TESTER = libft_tester.c

TEST_DIR = libft_tests

TESTS = ft_atoi_tests.c

all: test


test:
	@$(MAKE) -C $(LIBFT) all
	cp $(LIBFT)/$(LIBFT_A) ./
	@$(MAKE) -C $(LIBFT) fclean
	cc -Wall -Werror -Wextra $(WELCOME) && ./a.out
	rm a.out
	mkdir -p logs
	cc -Wall -Werror -Wextra $(TESTER) $(LIBFT_A) $(TEST_DIR)/*c && ./a.out
	rm a.out


fclean:
	rm $(LIBFT_A)