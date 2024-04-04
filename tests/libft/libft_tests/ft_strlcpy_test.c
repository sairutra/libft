#include "../libft_tester.h"
#include <bsd/string.h>

int fail_strlcpy = 0;

int strlcpy_cmp(int test_count, char *test1, char *test2, char* result, size_t n)
{
    FILE 	*errorLog;
    size_t result_ft;
	size_t result_org;
	char * test1_dub_org = strdup(test1);
	char * test2_dub_org = strdup(test2);
	char * test1_dub_ft = strdup(test1);
	char * test2_dub_ft = strdup(test2);


    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
    result_org = strlcpy(test1_dub_org, test2_dub_org, n);
	result_ft = ft_strlcpy(test1_dub_ft, test2_dub_ft, n);
    if(result_ft != result_org && strcmp(test1_dub_org, test1_dub_ft)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s %s\n", test1, test2);
        fprintf(errorLog,"n: %zu\n", n);
        fprintf(errorLog,"result: %s\n", result);
        fprintf(errorLog,"ft_strlcpy: %zu\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_strlcpy += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
	free(test1_dub_org);
	free(test2_dub_org);
	free(test1_dub_ft);
	free(test2_dub_ft);
    return(test_count + 1);
}

int strlcpy_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_strlcpy\n" RESET);
    test_count = strlcpy_cmp(test_count, "nfdsnkjd", "dlksadbs", "nfdsnkjddlksadbs", 16);
    test_count = strlcpy_cmp(test_count, "bobobbocob", "dlksadbs", "bobobbocobdlksadbs", 18);
    test_count = strlcpy_cmp(test_count, "a", "b", "ab", 2);
    test_count = strlcpy_cmp(test_count, "dfsfdsf?", "??cbdscds", "dfsfdsf???cbdscds", 17);
    test_count = strlcpy_cmp(test_count, "", "", "", 0);
    test_count = strlcpy_cmp(test_count, " ", " ", "  ", 2);
    return(fail_strlcpy);
}





