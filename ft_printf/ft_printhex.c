/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printhex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 21:06:04 by mynodeus      #+#    #+#                 */
/*   Updated: 2023/12/21 15:07:25 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_internal.h"

// this function retrieves the value from va_list
// and then passes it on t ft_hexconvert to convert the 
// hexidecimal value

int	ft_printhex(va_list args, char specifier)
{
	int				rtr;
	unsigned int	arg;

	rtr = 0;
	arg = va_arg(args, unsigned int);
	if (arg == 0)
	{
		rtr += ft_putchar_fd('0', 1);
		return (rtr);
	}
	rtr += ft_hexconvert(arg, specifier);
	return (rtr);
}
