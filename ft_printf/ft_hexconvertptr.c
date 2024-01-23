/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexconvertptr.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/03 10:43:41 by spenning      #+#    #+#                 */
/*   Updated: 2023/12/21 15:07:40 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_internal.h"

// This function converts the value passed from ft_printptr to 
// hexidecimal recursively

int	ft_hexconvertptr(long unsigned int arg)
{
	int	rtr;
	int	rem_int;

	rtr = 0;
	rem_int = 0;
	if (arg > 0)
	{
		rtr += ft_hexconvertptr(arg / 16);
		rem_int = arg % 16;
		if (rem_int > 9)
			rem_int += 55;
		else
			rem_int += 48;
		rtr += ft_putchar_fd(ft_tolower(rem_int), 1);
	}
	return (rtr);
}
