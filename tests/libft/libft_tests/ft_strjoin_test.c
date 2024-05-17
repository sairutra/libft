/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:57:44 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 05:59:57 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tester.h"
#include <string.h>

int	g_fail_strjoin = 0;

int	strjoin_cmp(int test_count, char *test1, char *test2, char* result)
{
	FILE	*errorlog;
	char	*ft;

	errorlog = fopen("logs/error_log.txt", "a");
	if (errorlog == NULL)
	{
		printf("Error opening log file\n");
		return (1);
	}
	ft = ft_strjoin(test1, test2);
	if (strcmp(ft, result))
		g_fail_strjoin += ft_log_str(test_count, errorlog, result, ft);
	else
		printf(GRN "%d OK " RESET, test_count);
	free(ft);
	return (test_count + 1);
}

int strjoin_test(void)
{
	int	test_count;

	test_count = 1;
	printf("\n");
	printf(BMAG "ft_strjoin\n" RESET);
	test_count = strjoin_cmp(test_count, "nfdsnkjd", "dlksadbs", "nfdsnkjddlksadbs");
	test_count = strjoin_cmp(test_count, "bobobbocob", "dlksadbs", "bobobbocobdlksadbs");
	test_count = strjoin_cmp(test_count, "a", "b", "ab");
	test_count = strjoin_cmp(test_count, "dfsfdsf?", "??cbdscds", "dfsfdsf???cbdscds");
	test_count = strjoin_cmp(test_count, "", "", "");
	test_count = strjoin_cmp(test_count, " ", " ", "  ");
	return(g_fail_strjoin);
}



