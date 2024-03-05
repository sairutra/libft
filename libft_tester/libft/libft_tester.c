/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_tester.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 12:54:09 by spenning      #+#    #+#                 */
/*   Updated: 2024/03/05 14:53:18 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"
#include <ctype.h>

int main ()
{
    int fail;

    fail = 0;
	fclose(fopen("logs/error_log.txt", "w"));
    fail += atoi_test();
    fail += bzero_test();
    fail += calloc_test();
    fail += is_test("ft_isalnum", isalnum, ft_isalnum);
    fail += is_test("ft_isalpha", isalpha, ft_isalpha);
    fail += is_test("ft_isascii", isascii, ft_isascii);
    fail += is_test("ft_isdigit", isdigit, ft_isdigit);
    fail += is_test("ft_isprint", isprint, ft_isprint);
    fail += itoa_test();
    fail += memchr_test();
    fail += memcmp_test();
    fail += memcpy_test();
    fail += memmove_test();
    fail += memset_test();
    fail += putchar_test();
    if(fail > 0)
        printf(RED "\nThere was an error. Check error_log.txt\n" RESET);
    printf("\n");
    return(0);
}