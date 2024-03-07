#include "../libft_tester.h"
#include <string.h>

int fail_strtrim = 0;

int strtrim_cmp(int test_count, char *test, char *ch, char *result)
{
    FILE 	*errorLog;
    char * result_ft;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
    result_ft = ft_strtrim(test, ch);
    if(strcmp(result, result_ft)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s char: %s\n", test, ch);
        fprintf(errorLog,"expected: %s\n", result);
        fprintf(errorLog,"ft_strtrim: %s\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_strtrim += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
	free(result_ft);
    return(test_count + 1);
}

int strtrim_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_strtrim\n" RESET);
    test_count = strtrim_cmp(test_count, "aaaaaabaaaaaa", "a", "b");
    test_count = strtrim_cmp(test_count, "bobobbocobedbobobbobob!", "!", "bobobbocobedbobobbobob");
    test_count = strtrim_cmp(test_count, "a", "b", "a");
    test_count = strtrim_cmp(test_count, "aaaaaabbbbcbbbbaaaaaa", "ab", "c");
    return(fail_strtrim);
}


