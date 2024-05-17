/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:44:11 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 05:51:35 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tester.h"
#include <string.h>

int	g_fail_strdup = 0;

int	strdup_cmp(int test_count, char *test)
{
	FILE	*errorlog;
	char	*org;
	char	*ft;

	errorlog = fopen("logs/error_log.txt", "a");
	if (errorlog == NULL)
	{
		printf("Error opening log file\n");
		return (1);
	}
	org = strdup(test);
	ft = ft_strdup(test);
	if (strcmp(ft, org))
		g_fail_strdup += ft_log_str(test_count, errorlog, org, ft);
	else
		printf(GRN "%d OK " RESET, test_count);
	free(org);
	free(ft);
	return (test_count + 1);
}

int	strdup_test(void)
{
	int	test_count;

	test_count = 1;
	printf("\n");
	printf(BMAG "ft_strdup\n" RESET);
	test_count = strdup_cmp(test_count, "nfdsnkjdsnciudsbccknd?cbdscds");
	test_count = strdup_cmp(test_count, "bobobbocobedbobobbobob!");
	test_count = strdup_cmp(test_count, "a");
	test_count = strdup_cmp(test_count, "dfsfdsf???cbdscds");
	test_count = strdup_cmp(test_count, "sdncdskj nkjsanckjdsncj\ndkj");
	return (g_fail_strdup);
}
