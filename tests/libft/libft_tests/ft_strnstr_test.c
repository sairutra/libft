/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 06:27:38 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 06:45:03 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tester.h"
#include <bsd/string.h>

int	g_fail_strnstr = 0;

int	strnstr_cmp(int test_count, char *test1, char *test2, size_t n)
{
	FILE	*errorlog;
	char	*ft;
	char	*org;

	errorlog = fopen("logs/error_log.txt", "a");
	if (errorlog == NULL)
	{
		printf("Error opening log file\n");
		return (1);
	}
	org = strnstr(test1, test2, n);
	ft = ft_strnstr(test1, test2, n);
	if (ft != org)
		g_fail_strnstr += ft_log_str(test_count, errorlog, org, ft);
	else
		printf(GRN "%d OK " RESET, test_count);
	return (test_count + 1);
}

int	strnstr_test(void)
{
	int	test_count;

	test_count = 1;
	printf("\n");
	printf(BMAG "ft_strnstr\n" RESET);
	test_count = strnstr_cmp(test_count, "nfdsnkjd", "dlkdsdbs", 16);
	test_count = strnstr_cmp(test_count, "bobobbocob", "dlksadob", 18);
	test_count = strnstr_cmp(test_count, "a", "b", 2);
	test_count = strnstr_cmp(test_count, "dfsfdsf?", "??", 17);
	test_count = strnstr_cmp(test_count, "", "", 0);
	test_count = strnstr_cmp(test_count, " ", " ", 2);
	return (g_fail_strnstr);
}
