#include "../libft_tester.h"
#include <string.h>

int fail_memchr = 0;

int memchr_cmp(int test_count, char *test, int c, size_t n)
{
    FILE 	*errorLog;
    char *org;
    char *ft;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        printf("Error opening log file\n");
        return 1;
    }

    org = memchr(test, c, n);
    ft = ft_memchr(test, c, n);
    if(org != ft) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s %d %ld\n", test, c, n);
        fprintf(errorLog,"memchr: %s\n", org);
        fprintf(errorLog,"address memchr: %p\n", org);
        fprintf(errorLog,"ft_memchr: %s\n", ft);
        fprintf(errorLog,"addresss t_memchr: %p\n", ft);
        fprintf(errorLog,"---------\n");
        fail_memchr += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int memchr_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_memchr\n" RESET);
    test_count = memchr_cmp(test_count, "fnjkdvbs", 'n', 5);
    test_count = memchr_cmp(test_count, "    scnaocuw9/", '/', 20);
    test_count = memchr_cmp(test_count, "fnjkdvbs", 'n', 0);
    test_count = memchr_cmp(test_count, "snsicnsk sjknsjanc", ' ', 10);
    test_count = memchr_cmp(test_count, "fnjkdvbs\n", '\200', 1000);
    test_count = memchr_cmp(test_count, "fnjkdvbs\n", '\n', 16);
    test_count = memchr_cmp(test_count, "fnjkdvb0", '\0', 20);
    return(fail_memchr);
}


