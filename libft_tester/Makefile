GNL_TEST_DIR = get_next_line/get_next_line_tester
PRINTF_TEST_DIR = ft_printf/ft_printf_tester
LIBFT_TEST_DIR = libft

.SILENT:

all:	LIBFT PRINTF GNL

LIBFT:
	@$(MAKE) --no-print-directory -C $(LIBFT_TEST_DIR) all
	@$(MAKE) --no-print-directory -C $(LIBFT_TEST_DIR) fclean

PRINTF:
	cp -r ../ft_printf ./
	@$(MAKE) --no-print-directory -C $(PRINTF_TEST_DIR) exe_welcome_lite
	rm -rf ft_printf

GNL:
	cp -r ../get_next_line	./
	@$(MAKE) --no-print-directory -C $(GNL_TEST_DIR) exe_welcome_lite
	rm -rf get_next_line
	
