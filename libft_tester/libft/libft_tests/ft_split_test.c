#include "../libft_tester.h"
#include <string.h>

int fail_split = 0;


int cmp_split(char ** ft_result, char* test, char* delim)
{
	int index;
	char *alloc = strdup(test);
	char * testret;

	index = 0;

	while(ft_result[index] != NULL)
	{
		testret = __strtok_r(alloc, delim, &alloc);
		if(strcmp(testret, ft_result[index]))
			return(-1);
		index++;
	}
	return(0);
}

int split_cmp(int test_count, char *test, char *delim)
{
    FILE 	*errorLog;
	char ** ft_result;
	int dif;
	int index;

	index = 0;
    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        printf("Error opening log file\n");
        return 1;
    }
    
    ft_result = ft_split(test, delim[0]);
	dif = cmp_split(ft_result, test, delim);
    if(dif != 0) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s delim: %s", test, delim);
		while(ft_result[index] != NULL)
		{
			fprintf(errorLog,"split: %s\n", ft_result[index]);
			index++;
		}
		fprintf(errorLog,"---------\n");
        fail_split += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int split_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_split\n" RESET);
    test_count = split_cmp(test_count, "aaa;bbb,", ";");
    test_count = split_cmp(test_count, "kokokokokokokoko", "o");
    test_count = split_cmp(test_count, "hdkjsahdkjsa|hdkjsahdkjsa", "|");
    test_count = split_cmp(test_count, "aaaa////aaaa//aa///", "/");
    return(fail_split);
}







