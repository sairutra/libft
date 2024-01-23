/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 23:03:23 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 14:35:07 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// These are header guards that prevent the double definitions in the
// source file. This prevents library dependency from double copying
// libraries. if libft is already defined if won't define it again.
// name is LIBFT_H because the name should be the full filename of the
// header file, in all caps, with underscores for spaces and ​punctuation.

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//these inclusions are needed to be able to use the write function from
// unistd library. and va_list from the stdarg.h library. and the libft library

# include <stdarg.h>
# include "../libft.h"

// This function prints out the format string + variables 
// depending on which format specifiers are given 
int		ft_printf(const char *format, ...);

#endif
