#include "../libft_tester.h"
#include <string.h>

int fail_strchr = 0;

int strchr_cmp(int test_count, char *test, int ch)
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
    result_org = strchr(test, ch);
    result_ft = ft_strchr(test, ch);
    if(result_org != result_ft) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s char: %c\n", test, ch);
        fprintf(errorLog,"strchr: %s\n", result_org);
        fprintf(errorLog,"&strchr: %p\n", result_org);
        fprintf(errorLog,"ft_strchr: %s\n", result_ft);
        fprintf(errorLog,"&ft_strchr: %p\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_strchr += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int strchr_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_strchr\n" RESET);
    test_count = strchr_cmp(test_count, "nfdsnkjdsnciudsbccknd?cbdscds", '?');
    test_count = strchr_cmp(test_count, "bobobbocobedbobobbobob!", '!');
    test_count = strchr_cmp(test_count, "a", 'b');
    test_count = strchr_cmp(test_count, "dfsfdsf???cbdscds", '?');
    test_count = strchr_cmp(test_count, "sdncdskj nkjsanckjdsncj\ndkj", '\n');
    return(fail_strchr);
}

