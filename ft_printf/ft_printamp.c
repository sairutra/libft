/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printamp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/03 10:44:00 by spenning      #+#    #+#                 */
/*   Updated: 2023/12/21 15:07:37 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_internal.h"

// This function uses ft_putchar_fd to print out ampersand

int	ft_printamp(void)
{
	int	rtr;

	rtr = 0;
	rtr += ft_putchar_fd('%', 1);
	return (rtr);
}
