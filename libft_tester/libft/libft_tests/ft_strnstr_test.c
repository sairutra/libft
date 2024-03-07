#include "../libft_tester.h"
#include <bsd/string.h>

int fail_strnstr = 0;

int strnstr_cmp(int test_count, char *test1, char *test2, size_t n)
{
    FILE 	*errorLog;
    char * result_ft;
	char * result_org;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
    result_org = strnstr(test1, test2, n);
	result_ft = ft_strnstr(test1, test2, n);
    if(result_ft != result_org) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s %s\n", test1, test2);
        fprintf(errorLog,"n: %zu\n", n);
        fprintf(errorLog,"strnstr: %s\n", result_org);
        fprintf(errorLog,"ft_strnstr: %s\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_strnstr += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int strnstr_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_strnstr\n" RESET);
    test_count = strnstr_cmp(test_count, "nfdsnkjd", "dlkdsdbs", 16);
    test_count = strnstr_cmp(test_count, "bobobbocob", "dlksadob", 18);
    test_count = strnstr_cmp(test_count, "a", "b", 2);
    test_count = strnstr_cmp(test_count, "dfsfdsf?", "??", 17);
    test_count = strnstr_cmp(test_count, "", "", 0);
    test_count = strnstr_cmp(test_count, " ", " ",  2);
    return(fail_strnstr);
}







