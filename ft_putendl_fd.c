/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 19:13:18 by spenning      #+#    #+#                 */
/*   Updated: 2023/10/21 18:13:47 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	endl;

	endl = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &endl, 1);
}
