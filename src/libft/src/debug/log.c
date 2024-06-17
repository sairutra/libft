/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   log.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/20 17:51:10 by spenning      #+#    #+#                 */
/*   Updated: 2024/06/17 22:00:54 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

int	ft_log(char *path, char *format, ...)
{
	FILE	*fptr;
	char	*dir;
	va_list	ptr;
	
	dir = ft_dirname(path);
	if (ft_check_file(dir))
	{
		if (ft_create_dir(dir))
		{
			free(dir);
			return (EXIT_FAILURE);
		}
	}
	free(dir);
	fptr = fopen(path, "a+");
	if (fptr == NULL)
		return (EXIT_FAILURE);
	va_start(ptr, format);
	vfprintf(fptr, format, ptr);
	va_end(ptr);
	fclose(fptr);
	return (EXIT_SUCCESS);
}
