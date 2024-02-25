#include "../libft_tester.h"
#include <limits.h>
int fail_itoa = 0;

int itoa_cmp(int test_count, int test, char * test_case)
{
    FILE 	*errorLog;
    char *  result_org ;
    char * result_ft ;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
    result_org = test_case;
    result_ft = ft_itoa(test);
    if(result_ft == NULL)
    {
        printf("error with result_ft\n");
        return 1;
    }    
    if(strcmp(result_org, result_ft)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %d\n", test);
        fprintf(errorLog,"itoa: %s\n", result_org);
        fprintf(errorLog,"ft_itoa: %s\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_itoa += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    free(result_ft);
    return(test_count + 1);
}

int itoa_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_itoa\n" RESET);
    test_count = itoa_cmp(test_count, 0, "0");
    test_count = itoa_cmp(test_count, 1, "1");
    test_count = itoa_cmp(test_count, 12, "12");
    test_count = itoa_cmp(test_count, 123, "123");
    test_count = itoa_cmp(test_count, 1234, "1234");
    test_count = itoa_cmp(test_count, 12345, "12345");
    test_count = itoa_cmp(test_count, -123456, "-123456");
    test_count = itoa_cmp(test_count, INT_MAX, "2147483647");
    test_count = itoa_cmp(test_count, INT_MIN, "-2147483648");
    return(fail_itoa);
}

