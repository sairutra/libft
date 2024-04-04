#include "ft_printftests.h"
#include <limits.h>

void category_c();
void category_s();
void category_p();
void category_d();
void category_i();
void category_u();
void category_x();
void category_X();


void category_c()
{
	int outcome;
	int ft_outcome;
	int file_outcome;
	int len_outcome;
	int test_count;

	outcome = 0;
	ft_outcome = 0;
	file_outcome = 0;
	len_outcome = 0;
	test_count = 0;

	printf("\n");
	printf(BMAG "%%c\n" RESET);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("lol %c", '1'); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("lol %c", '1');
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("lol %c", '\200'); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("lol %c", '\200');
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%c%c%c", '\0', 'l', -42); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%c%c%c", '\0', 'l', -42);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%c%c%c", 23647238, 265, -42); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%c%c%c",  23647238, 265, -42);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%c%c%c", 0, -1, 0); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%c%c%c",  0, -1, 0);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	

	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}

void category_s()
{
	int outcome;
	int ft_outcome;
	int file_outcome;
	int len_outcome;
	int test_count;

	outcome = 0;
	ft_outcome = 0;
	file_outcome = 0;
	len_outcome = 0;
	test_count = 0;

	printf("\n");
	printf(BMAG "%%s\n" RESET);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("lol %s", "lololol"); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("lol %s", "lololol");
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("lol %s", "\200" ); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("lol %s", "\200");
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%s", ""); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%s", "");
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	printf("\n");
	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}

void category_p()
{
	int outcome;
	int ft_outcome;
	int file_outcome;
	int len_outcome;
	int test_count;

	outcome = 0;
	ft_outcome = 0;
	file_outcome = 0;
	len_outcome = 0;
	test_count = 0;

	printf(BMAG "%%p\n" RESET);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%p", ""); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%p", "");
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%p", NULL); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%p", NULL);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%p", (void *)-14523); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%p", (void *)-14523);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("0x%p-", (void *)ULONG_MAX); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("0x%p-", (void *)ULONG_MAX);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);


	printf("\n");

	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}

void category_d()
{
	int outcome;
	int ft_outcome;
	int file_outcome;
	int len_outcome;
	int test_count;

	outcome = 0;
	ft_outcome = 0;
	file_outcome = 0;
	len_outcome = 0;
	test_count = 0;

	printf(BMAG "%%d\n" RESET);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%d", 0); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%d", 0);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%d", -10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%d", -10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%d", -200000); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%d", -200000);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%d", -6000023); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%d", -6000023);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%d", 10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%d", 10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%d", 10000); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%d", 10000);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%d", 100023); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%d", 100023);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%d", INT_MAX); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%d", INT_MAX);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%d", INT_MIN); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%d", INT_MIN);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("dgs%dxx", 10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("dgs%dxx", 10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%d%dd%d", 1, 2, -3); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%d%dd%d", 1, 2, -3);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	printf("\n");

	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}

void category_i()
{
	int outcome;
	int ft_outcome;
	int file_outcome;
	int len_outcome;
	int test_count;

	outcome = 0;
	ft_outcome = 0;
	file_outcome = 0;
	len_outcome = 0;
	test_count = 0;

	printf(BMAG "%%i\n" RESET);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%i", 0); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%i", 0);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%i", -10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%i", -10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%i", -200000); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%i", -200000);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%i", -6000023); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%i", -6000023);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%i", 10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%i", 10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%i", 10000); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%i", 10000);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%i", 100023); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%i", 100023);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%i", INT_MAX); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%i", INT_MAX);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%i", INT_MIN); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%i", INT_MIN);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("dgs%ixx", 10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("dgs%ixx", 10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%i%ii%i", 1, 2, -3); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%i%ii%i", 1, 2, -3);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	printf("\n");

	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}

void category_u()
{
	int outcome;
	int ft_outcome;
	int file_outcome;
	int len_outcome;
	int test_count;

	outcome = 0;
	ft_outcome = 0;
	file_outcome = 0;
	len_outcome = 0;
	test_count = 0;

	printf(BMAG "%%u\n" RESET);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%u", 0); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%u", 0);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%u", -10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%u", -10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%u", -200000); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%u", -200000);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%u", -6000023); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%u", -6000023);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%u", 10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%u", 10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%u", 10000); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%u", 10000);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%u", 100023); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%u", 100023);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%u", INT_MAX); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%u", INT_MAX);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%u", INT_MIN); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%u", INT_MIN);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("dgs%uxx", 10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("dgs%uxx", 10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%u%uu%u", 1, 2, -3); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%u%uu%u", 1, 2, -3);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	printf("\n");

	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}

void category_x()
{
	int outcome;
	int ft_outcome;
	int file_outcome;
	int len_outcome;
	int test_count;

	outcome = 0;
	ft_outcome = 0;
	file_outcome = 0;
	len_outcome = 0;
	test_count = 0;

	printf(BMAG "%%x\n" RESET);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%x", 0); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%x", 0);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%x", -10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%x", -10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%x", -200000); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%x", -200000);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%x", -6000023); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%x", -6000023);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%x", 10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%x", 10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%x", 10000); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%x", 10000);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%x", 100023); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%x", 100023);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%x", INT_MAX); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%x", INT_MAX);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%x", INT_MIN); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%x", INT_MIN);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("dgs%xxx", 10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("dgs%xxx", 10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%x%xx%x", 1, 2, -3); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%x%xx%x", 1, 2, -3);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	printf("\n");

	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}

void category_X()
{
	int outcome;
	int ft_outcome;
	int file_outcome;
	int len_outcome;
	int test_count;

	outcome = 0;
	ft_outcome = 0;
	file_outcome = 0;
	len_outcome = 0;
	test_count = 0;

	printf(BMAG "%%X\n" RESET);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%X", 0); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%X", 0);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%X", -10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%X", -10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);
	
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%X", -200000); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%X", -200000);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%X", -6000023); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%X", -6000023);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%X", 10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%X", 10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%X", 10000); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%X", 10000);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%X", 100023); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%X", 100023);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%X", INT_MAX); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%X", INT_MAX);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%X", INT_MIN); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%X", INT_MIN);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("dgs%Xxx", 10); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("dgs%Xxx", 10);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("%X%XX%X", 1, 2, -3); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("%X%XX%X", 1, 2, -3);
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	if(len_outcome != 0 || file_outcome != 0) 
		printf(RED "%d FAIL "RESET, test_count);
	else
		printf(GRN "%d OK " RESET, test_count);

	printf("\n");

	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}