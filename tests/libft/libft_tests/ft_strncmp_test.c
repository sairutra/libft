#include "../libft_tester.h"
#include <bsd/string.h>

int fail_strncmp = 0;

int strncmp_cmp(int test_count, char *test1, char *test2, size_t n)
{
    FILE 	*errorLog;
    size_t result_ft;
	size_t result_org;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
    result_org = strncmp(test1, test2, n);
	result_ft = ft_strncmp(test1, test2, n);
    if(result_ft != result_org) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s %s\n", test1, test2);
        fprintf(errorLog,"n: %zu\n", n);
        fprintf(errorLog,"strncmp: %zu\n", result_org);
        fprintf(errorLog,"ft_strncmp: %zu\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_strncmp += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int strncmp_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_strncmp\n" RESET);
    test_count = strncmp_cmp(test_count, "nfdsnkjd", "dlksadbs", 16);
    test_count = strncmp_cmp(test_count, "bobobbocob", "dlksadbs", 18);
    test_count = strncmp_cmp(test_count, "a", "b", 2);
    test_count = strncmp_cmp(test_count, "dfsfdsf?", "??cbdscds", 17);
    test_count = strncmp_cmp(test_count, "", "", 0);
    test_count = strncmp_cmp(test_count, " ", " ",  2);
    return(fail_strncmp);
}






