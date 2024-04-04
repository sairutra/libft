#include "../libft_tester.h"
#include <string.h>

int fail_striteri = 0;

void test_function(unsigned int c, char * s)
{
	s[0] = s[0]+c;
}

int striteri_cmp(int test_count, char *test, char *result)
{
    FILE 	*errorLog;
    char * test_dub = strdup(test);

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }

    ft_striteri(test_dub, test_function);
    if(strcmp(test_dub, result)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s\n", test);
        fprintf(errorLog,"test_dub: %s\n", test_dub);
        fprintf(errorLog,"expected: %s\n", result);
        fprintf(errorLog,"---------\n");
        fail_striteri += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
	free(test_dub);
    return(test_count + 1);
}

int striteri_test()
{
    int  test_count = 1;

    printf("\n");
	printf(BMAG "ft_striteri\n" RESET);
    test_count = striteri_cmp(test_count, "123", "135");
	test_count = striteri_cmp(test_count, "abc", "ace");
	test_count = striteri_cmp(test_count, "ABC", "ACE");
    return(fail_striteri);
}



