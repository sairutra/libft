/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:21:40 by spenning          #+#    #+#             */
/*   Updated: 2024/05/16 11:23:46 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tester.h"

int ft_log(int test_count, FILE *errorlog, int result_org, int result_ft)
{
	printf(RED "%d FAIL "RESET, test_count);
	fprintf(errorlog, "error\n");
	fprintf(errorlog, "test number: %d\n", test_count);
	fprintf(errorlog, "atoi: %d\n", result_org);
	fprintf(errorlog, "ft_atoi: %d\n", result_ft);
	fprintf(errorlog, "---------\n");
	return (1);
}
