/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   log.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/20 17:51:10 by spenning      #+#    #+#                 */
/*   Updated: 2024/06/17 16:50:24 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

int	ft_log(char *path, char *file, char *log)
{
	FILE	*fptr;
	char	*temp;
	char	*temp2;

	if (ft_check_file(path))
	{
		if (ft_create_dir(path))
			return (EXIT_FAILURE);
	}
	temp = ft_strjoin(path, "/");
	if (!temp)
		return (EXIT_FAILURE);
	temp2 = ft_strjoin(temp, file);
	if (!temp2)
		return (EXIT_FAILURE);
	free(temp);
	fptr = fopen(temp2, "a+");
	free(temp2);
	if (fptr == NULL)
		return (EXIT_FAILURE);
	fprintf(fptr, "%s\n", log);
	fclose(fptr);
	return (EXIT_SUCCESS);
}
