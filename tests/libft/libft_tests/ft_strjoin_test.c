#include "../libft_tester.h"
#include <string.h>

int fail_strjoin = 0;

int strjoin_cmp(int test_count, char *test1, char *test2, char* result)
{
    FILE 	*errorLog;
    char * result_ft;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
    result_ft = ft_strjoin(test1, test2);
    if(strcmp(result_ft, result)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s %s\n", test1, test2);
        fprintf(errorLog,"result: %s\n", result);
        fprintf(errorLog,"ft_strjoin: %s\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_strjoin += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
	free(result_ft);
    return(test_count + 1);
}

int strjoin_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_strjoin\n" RESET);
    test_count = strjoin_cmp(test_count, "nfdsnkjd", "dlksadbs", "nfdsnkjddlksadbs");
    test_count = strjoin_cmp(test_count, "bobobbocob", "dlksadbs", "bobobbocobdlksadbs");
    test_count = strjoin_cmp(test_count, "a", "b", "ab");
    test_count = strjoin_cmp(test_count, "dfsfdsf?", "??cbdscds", "dfsfdsf???cbdscds");
    test_count = strjoin_cmp(test_count, "", "", "");
    test_count = strjoin_cmp(test_count, " ", " ", "  ");
    return(fail_strjoin);
}



