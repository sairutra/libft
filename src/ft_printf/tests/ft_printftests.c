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

#include "ft_printftests.h"
# include "../inc/ft_printf.h"

int main ()
{
	fclose(fopen("logs/error_log.txt", "w"));
	category_c();
	category_s();
	category_p();
	category_d();
	category_i();
	category_u();
	category_x();
	category_X();
}