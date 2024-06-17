/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dir.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 18:10:24 by spenning      #+#    #+#                 */
/*   Updated: 2024/06/17 16:15:43 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

int	ft_create_dir(char *path)
{
	struct stat	st;

	ft_memset(&st, 0, sizeof(st));
	if (stat(path, &st) != -1)
		return (EXIT_FAILURE);
	if (mkdir(path, 0700))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
