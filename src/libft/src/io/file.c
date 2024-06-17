/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 18:10:24 by spenning      #+#    #+#                 */
/*   Updated: 2024/06/17 21:57:20 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

char *ft_dirname(char *path)
{
	int		index;
	int		last;
	char	*ret;

	index = 0;
	last = 0;
	while (path[index] != '\0')
	{
		if (path[index] == '/')
			last = (index + 1);
		index++;
	}
	if (last == 0)
		return (NULL);
	ret = ft_calloc(last + 1, 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, path, last);
	return (ret);
}

int	ft_check_file(char *path)
{
	struct stat	st;

	ft_memset(&st, 0, sizeof(st));
	if (stat(path, &st) != -1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_create_file(char *path)
{
	FILE	*fptr;

	fptr = fopen(path, "w");
	if (fptr == NULL)
		return (EXIT_FAILURE);
	fclose(fptr);
	return (EXIT_SUCCESS);
}
