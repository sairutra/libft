/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printftests.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 12:54:09 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/30 15:20:37 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"


int main ()
{
    int fail;

    fail = 0;
	fclose(fopen("logs/error_log.txt", "w"));
    fail += atoi_test();
    fail += bzero_test();
    fail += calloc_test();
    fail += alnum_test();
    if(fail > 0)
        printf(RED "\nThere was an error. Check error_log.txt\n" RESET);
    printf("\n");
    return(0);
}