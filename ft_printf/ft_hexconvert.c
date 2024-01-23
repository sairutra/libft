/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexconvert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/03 10:43:41 by spenning      #+#    #+#                 */
/*   Updated: 2023/12/21 15:07:43 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_internal.h"

// This functions retrieves the arg value from ft_printhex
// does the conversion and then based on the specifier passed
// it will print in upper or lowercase

int	ft_hexconvert(unsigned int arg, char specifier)
{
	int	rtr;
	int	rem_int;

	rtr = 0;
	rem_int = 0;
	if (arg > 0)
	{
		rtr += ft_hexconvert(arg / 16, specifier);
		rem_int = arg % 16;
		if (rem_int > 9)
			rem_int += 55;
		else
			rem_int += 48;
		if (specifier == 'x')
			rtr += ft_putchar_fd(ft_tolower(rem_int), 1);
		if (specifier == 'X')
			rtr += ft_putchar_fd(ft_toupper(rem_int), 1);
	}
	return (rtr);
}
