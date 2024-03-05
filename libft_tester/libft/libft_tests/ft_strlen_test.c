#include "../libft_tester.h"
#include <string.h>

int fail_strlen = 0;

int strlen_cmp(int test_count, char *test)
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
    result_org = strlen(test);
	result_ft = ft_strlen(test);
    if(result_ft != result_org) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s\n", test);
        fprintf(errorLog,"strlen: %zu\n", result_org);
        fprintf(errorLog,"ft_strlen: %zu\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_strlen += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int strlen_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_strlen\n" RESET);
    test_count = strlen_cmp(test_count, "nfdsnkjd");
    test_count = strlen_cmp(test_count, "bobobbocob");
    test_count = strlen_cmp(test_count, "a");
    test_count = strlen_cmp(test_count, "dfsfdsf?");
    test_count = strlen_cmp(test_count, "");
    test_count = strlen_cmp(test_count, " ");
    return(fail_strlen);
}





