/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:00:52 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:53:16 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

int	ft_isalnum(int c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91)
		|| (c > 96 && c < 123))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
