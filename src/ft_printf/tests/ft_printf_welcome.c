#include "ft_printftests.h"
#include <stdio.h>

void welcome_screen()
{
	printf(CYN "<==================================================================================>\n" RESET);
	printf(CYN "||                                                                                ||\n" RESET);
	printf(CYN "||    ||      |      ||  ||||||  ||     |||||   ||||||    |||| |||||   ||||||     ||\n" RESET);
	printf(CYN "||    ||     |||     ||  ||      ||    ||      ||    ||  ||   ||   ||  ||         ||\n" RESET);
	printf(CYN "||    ||    || ||    ||  ||||||  ||    ||      ||    ||  ||   ||   ||  ||||||     ||\n" RESET);
	printf(CYN "||     ||  ||   ||  ||   ||      ||    ||      ||    ||  ||   ||   ||  ||         ||\n" RESET);
	printf(CYN "||      ||||     ||||    ||||||  |||||  |||||   ||||||   ||   ||   ||  ||||||     ||\n" RESET);
	printf(CYN "||                                                                                ||\n" RESET);
	printf(CYN "<==================================================================================>\n" RESET);
	printf(CYN "+                                                                                  +\n" RESET);
	printf(CYN "+                               " RESET);
	printf(YEL "ft_printf" RESET);
	printf(CYN " tester  " RESET);
	printf(CYN "                                 +\n" RESET);
	printf(CYN "+                                  by spenning                                     +\n" RESET);
	printf(CYN "+                                                                                  +\n" RESET);
	printf(CYN "<==================================================================================>\n" RESET);
}

int main()
{
	welcome_screen();
	return(0);
}
