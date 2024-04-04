#include "../libft_tester.h"
#include <ctype.h>

int fail_isto = 0;

int isto_cmp(int test_count, int c, char *function_name,int (*f)(int), int (*ft)(int))
{
    FILE *errorLog;
    int org_func;
    int ft_func;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        printf("Error opening log file\n");
        return 1;
    }

    org_func = f(c);
    ft_func = ft(c);
    if(org_func == 0 && ft_func != 0) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %d\n", c);
        fprintf(errorLog,"%s: %c\n", function_name + 3,org_func);
        fprintf(errorLog,"%s: %c\n", function_name,ft_func);
        fprintf(errorLog,"---------\n");
        fail_isto += 1;
    }
    else
        printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int isto_test(char * function_name, int (*f)(int), int (*ft)(int))
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "%s\n", function_name);
    printf(RESET);
    test_count = isto_cmp(test_count, 'a', function_name, f, ft);
    test_count = isto_cmp(test_count, 'A', function_name, f, ft);
    test_count = isto_cmp(test_count, 'z', function_name, f, ft);
    test_count = isto_cmp(test_count, '\n', function_name, f, ft);
    test_count = isto_cmp(test_count, '\200', function_name, f, ft);
    test_count = isto_cmp(test_count, '\100', function_name, f, ft);
    test_count = isto_cmp(test_count, 359, function_name, f, ft);
    test_count = isto_cmp(test_count, 255, function_name, f, ft);
    test_count = isto_cmp(test_count, '"', function_name, f, ft);
    test_count = isto_cmp(test_count, ' ', function_name, f, ft);
    test_count = isto_cmp(test_count, 1243, function_name, f, ft);
    return(fail_isto);
}





