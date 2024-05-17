/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 06:01:09 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 07:02:19 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tester.h"
#include <bsd/string.h>

int	g_fail_strlcpy = 0;

int	strlift(char *output, char *test, char *test2, size_t n)
{
	char	*test2_dub;
	size_t	ret;

	output = strdup(test);
	test2_dub = strdup(test2);
	if (output == NULL || test2_dub == NULL)
	{
		if (output)
			free(output);
		if (test2_dub)
			free(test2_dub);
		printf("Error with initft\n");
		return (0);
	}
	ret = ft_strlcpy(output, test2_dub, n);
	free(test2_dub);
	return (ret);
}

int	strliorg(char *output, char *test, char *test2, size_t n)
{
	char	*test2_dub;
	size_t	ret;

	output = strdup(test);
	test2_dub = strdup(test2);
	if (output == NULL || test2_dub == NULL)
	{
		if (output)
			free(output);
		if (test2_dub)
			free(test2_dub);
		printf("Error with initft\n");
		return (0);
	}
	ret = strlcpy(output, test2_dub, n);
	free(test2_dub);
	return (ret);
}

int	strlcpy_cmp(int test_count, char *t1, char *t2, size_t n)
{
	FILE	*errorlog;
	char	*org;
	char	*ft;

	org = NULL;
	ft = NULL;
	errorlog = fopen("logs/error_log.txt", "a");
	if (errorlog == NULL)
	{
		printf("Error opening log file\n");
		return (1);
	}
	if (strlift(ft, t1, t2, n) != strliorg(org, t1, t2, n) && strcmp(org, ft))
		g_fail_strlcpy += ft_log_str(test_count, errorlog, org, ft);
	else
		printf(GRN "%d OK " RESET, test_count);
	free(org);
	free(ft);
	fclose(errorlog);
	return (test_count + 1);
}

int	strlcpy_test(void)
{
	int	test_count;

	test_count = 1;
	printf("\n");
	printf(BMAG "ft_strlcpy\n" RESET);
	test_count = strlcpy_cmp(test_count, "nfdsnkjd", "dlksadbs", 16);
	test_count = strlcpy_cmp(test_count, "bobobbocob", "dlksadbs", 18);
	test_count = strlcpy_cmp(test_count, "a", "b", 2);
	test_count = strlcpy_cmp(test_count, "dfsfdsf?", "??cbdscds", 17);
	test_count = strlcpy_cmp(test_count, "", "", 0);
	test_count = strlcpy_cmp(test_count, " ", " ", 2);
	return (g_fail_strlcpy);
}
