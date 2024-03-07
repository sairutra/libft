#include "../libft_tester.h"
#include <string.h>

int fail_substr = 0;

int substr_cmp(int test_count, char *test, unsigned int start, size_t n, char * result)
{
    FILE 	*errorLog;
    char * result_ft;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
    result_ft = ft_substr(test, start, n);
    if(strcmp(result_ft, result)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s start: %d n: %zu\n", test, start, n);
        fprintf(errorLog,"expected: %s\n", result);
        fprintf(errorLog,"ft_substr: %s\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_substr += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int substr_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_substr\n" RESET);
    test_count = substr_cmp(test_count, "nfdsnkjdsnciudsbccknd?cbdscds", 5, 8, "kjdsnciu");
    test_count = substr_cmp(test_count, "bobobbocobedbobobbobob!", 0, 23, "bobobbocobedbobobbobob!");
    // test_count = substr_cmp(test_count, "a", 2, 5, NULL);
    test_count = substr_cmp(test_count, "dfsfdsf???cbdscds", 2, 14,"sfdsf???cbdscd");
    return(fail_substr);
}



