#include "../libft_tester.h"
#include <string.h>

int fail_strdup = 0;

int strdup_cmp(int test_count, char *test)
{
    FILE 	*errorLog;
    char * result_org;
    char * result_ft;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
    result_org = strdup(test);
    result_ft = ft_strdup(test);
    if(strcmp(result_ft, result_org)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s\n", test);
        fprintf(errorLog,"strdup: %s\n", result_org);
        fprintf(errorLog,"ft_strdup: %s\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_strdup += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
	free(result_ft);
	free(result_org);
    return(test_count + 1);
}

int strdup_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_strdup\n" RESET);
    test_count = strdup_cmp(test_count, "nfdsnkjdsnciudsbccknd?cbdscds");
    test_count = strdup_cmp(test_count, "bobobbocobedbobobbobob!");
    test_count = strdup_cmp(test_count, "a");
    test_count = strdup_cmp(test_count, "dfsfdsf???cbdscds");
    test_count = strdup_cmp(test_count, "sdncdskj nkjsanckjdsncj\ndkj");
    return(fail_strdup);
}


