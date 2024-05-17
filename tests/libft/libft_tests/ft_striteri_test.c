/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:52:33 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 05:56:47 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tester.h"
#include <string.h>

int	g_fail_striteri = 0;

void	test_function(unsigned int c, char *s)
{
	s[0] = s[0] + c;
}

int	striteri_cmp(int test_count, char *test, char *result)
{
	FILE	*errorlog;
	char	*test_dub;

	test_dub = strdup(test);
	errorlog = fopen("logs/error_log.txt", "a");
	if (errorlog == NULL)
	{
		printf("Error opening log file\n");
		return (1);
	}
	ft_striteri(test_dub, test_function);
	if (strcmp(test_dub, result))
		g_fail_striteri += ft_log_str(test_count, errorlog, test, test_dub);
	else
		printf(GRN "%d OK " RESET, test_count);
	free(test_dub);
	return (test_count + 1);
}

int	striteri_test(void)
{
	int	test_count;

	test_count = 1;
	printf("\n");
	printf(BMAG "ft_striteri\n" RESET);
	test_count = striteri_cmp(test_count, "123", "135");
	test_count = striteri_cmp(test_count, "abc", "ace");
	test_count = striteri_cmp(test_count, "ABC", "ACE");
	return (g_fail_striteri);
}
