#include "../libft_tester.h"
#include <string.h>

int fail_memcmp = 0;

int memcmp_cmp(int test_count, char *test, char *test2, size_t n)
{
    FILE 	*errorLog;
    int org;
    int ft;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        printf("Error opening log file\n");
        return 1;
    }
    org = memcmp(test, test2, n);
    ft = ft_memcmp(test, test2, n);
    if(org != ft) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s %s %ld\n", test, test2, n);
        fprintf(errorLog,"memcmp: %d\n", org);
        fprintf(errorLog,"ft_memcmp: %d\n", ft);
        fprintf(errorLog,"---------\n");
        fail_memcmp += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int memcmp_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_memcmp\n" RESET);
    test_count = memcmp_cmp(test_count, "fnjkdvbs", "fnjkdvbs", 5);
    test_count = memcmp_cmp(test_count, "    scnaocuw9/", "    scnaocuw9/", 20);
    test_count = memcmp_cmp(test_count, "fnjkdvbs", "fnjkdvss",  20);
    test_count = memcmp_cmp(test_count, "snsicnsk sjknsjanc", "snsicnsk sjknsjanc",  10);
    test_count = memcmp_cmp(test_count, "fnjkdvbs\n", "fnjkdvbs\n",  1000);
    test_count = memcmp_cmp(test_count, "fnjkdvbs\n", "fnjkdvbs\n",  16);
    test_count = memcmp_cmp(test_count, "fnjkdvb0", "fnjkdvb0",  20);
    test_count = memcmp_cmp(test_count, "NULL", "NULL",  0);
    return(fail_memcmp);
}



