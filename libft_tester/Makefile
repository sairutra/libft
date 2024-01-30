GNL_TEST_DIR = get_next_line/get_next_line_tester
PRINTF_TEST_DIR = ft_printf/ft_printf_tester

all:	GNL PRINTF

GNL:
	cp -r ../get_next_line	./
	@$(MAKE) -C $(GNL_TEST_DIR) all
	rm -rf get_next_line

PRINTF:
	cp -r ../ft_printf ./
	@$(MAKE) -C $(PRINTF_TEST_DIR) all
	rm -rf ft_printf
	
