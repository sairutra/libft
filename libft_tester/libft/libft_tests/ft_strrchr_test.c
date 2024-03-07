#include "../libft_tester.h"
#include <string.h>

// this tester could be joined together with ft_strchr with function pointers

int fail_strrchr = 0;

int strrchr_cmp(int test_count, char *test, int ch)
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
    result_org = strrchr(test, ch);
    result_ft = ft_strrchr(test, ch);
    if(result_org != result_ft) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s char: %c\n", test, ch);
        fprintf(errorLog,"strrchr: %s\n", result_org);
        fprintf(errorLog,"&strrchr: %p\n", result_org);
        fprintf(errorLog,"ft_strrchr: %s\n", result_ft);
        fprintf(errorLog,"&ft_strrchr: %p\n", result_ft);
        fprintf(errorLog,"---------\n");
        fail_strrchr += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int strrchr_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_strrchr\n" RESET);
    test_count = strrchr_cmp(test_count, "nfdsnkjdsnciudsbccknd?cbdscds", '?');
    test_count = strrchr_cmp(test_count, "bobobbocobedbobobbobob!", '!');
    test_count = strrchr_cmp(test_count, "a", 'b');
    test_count = strrchr_cmp(test_count, "dfsfdsf???cbdscds", '?');
    test_count = strrchr_cmp(test_count, "sdncdskj nkjsanckjdsncj\ndkj", '\n');
    return(fail_strrchr);
}


