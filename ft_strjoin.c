/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 19:03:23 by spenning      #+#    #+#                 */
/*   Updated: 2023/10/21 19:03:16 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ns_cptr;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ns_cptr = (char *)malloc((len_s1 + len_s2) + 1);
	if (ns_cptr == NULL)
		return (NULL);
	ft_strlcpy(ns_cptr, s1, len_s1 + 1);
	ft_strlcat(ns_cptr, s2, len_s1 + len_s2 + 1);
	if (ft_strlen(ns_cptr) != len_s1 + len_s2)
		return (NULL);
	return (ns_cptr);
}
