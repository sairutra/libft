/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:32:28 by spenning      #+#    #+#                 */
/*   Updated: 2023/10/21 18:09:04 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	long unsigned int	index;
	char				*cptr;

	cptr = (char *)s;
	index = 0;
	while (index < n)
	{
		cptr[index] = (const int)c;
		index++;
	}
	return (cptr);
}
