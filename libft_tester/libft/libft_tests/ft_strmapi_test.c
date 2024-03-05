#include "../libft_tester.h"
#include <string.h>

int fail_strmapi = 0;

char test_function_mapi(unsigned int c, char s)
{
	char r;
	r = s+c;
	return(r);
}

int strmapi_cmp(int test_count, char *test, char *result)
{
    FILE 	*errorLog;
    char * test_dub = strdup(test);
	char * ft_result;
    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }

    ft_result = ft_strmapi(test_dub, &test_function_mapi);
    if(strcmp(ft_result, result)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s\n", test);
        fprintf(errorLog,"result: %s\n", ft_result);
        fprintf(errorLog,"expected: %s\n", result);
        fprintf(errorLog,"---------\n");
        fail_strmapi += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
	free(test_dub);
	free(ft_result);
    return(test_count + 1);
}

int strmapi_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_strmapi\n" RESET);
    test_count = strmapi_cmp(test_count, "123", "135");
	test_count = strmapi_cmp(test_count, "abc", "ace");
	test_count = strmapi_cmp(test_count, "ABC", "ACE");
    return(fail_strmapi);
}




