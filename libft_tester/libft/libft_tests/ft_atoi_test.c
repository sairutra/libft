#include "../libft_tester.h"

int fail_atoi = 0;

int atoi_cmp(int test_count, char *test)
{
    FILE 	*errorLog;
    int  result_org = 0;
    int  result_ft = 0;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
    result_org = atoi(test);
    result_ft = ft_atoi(test);
    if(result_org != result_ft) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s\n", test);
        fprintf(errorLog,"atoi: %d\n", result_org);
        fprintf(errorLog,"ft_atoi: %d\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_atoi += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int atoi_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_atoi\n" RESET);
    test_count = atoi_cmp(test_count, "1");
    test_count = atoi_cmp(test_count, "12");
    test_count = atoi_cmp(test_count, "123");
    test_count = atoi_cmp(test_count, "1234");
    test_count = atoi_cmp(test_count, "  12345");
    test_count = atoi_cmp(test_count, "123 456");
    test_count = atoi_cmp(test_count, "A2143244535");
    test_count = atoi_cmp(test_count, "2143244535");
    test_count = atoi_cmp(test_count, "");
    test_count = atoi_cmp(test_count, "asbj");
    test_count = atoi_cmp(test_count, "");
    test_count = atoi_cmp(test_count, "       ");
    return(fail_atoi);
}
