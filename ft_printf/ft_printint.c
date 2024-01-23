/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printint.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/03 10:44:37 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 14:27:49 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_internal.h"

// This function takes the value from va_list and then
// uses ft_putnbr_fd to print out the value

int	ft_printint(va_list args)
{
	int	arg;
	int	rtr;

	arg = va_arg(args, int);
	rtr = 0;
	rtr = ft_putnbr_fd(arg, 1);
	return (rtr);
}
