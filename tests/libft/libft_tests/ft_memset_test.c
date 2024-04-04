#include "../libft_tester.h"
#include <string.h>

int fail_memset = 0;

int memset_cmp(int test_count, char *test, int c, size_t n)
{
    FILE 	*errorLog;
    char *org;
    char *ft;
    char *test_alloc;
    char *test2_alloc;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        printf("Error opening log file\n");
        return 1;
    }
    test_alloc = strdup(test);
    test2_alloc = strdup(test); 
    if(test_alloc == NULL || test2_alloc == NULL)
    {   
        if(test_alloc)
            free(test_alloc);
        if(test2_alloc)
            free(test2_alloc);
        printf("Error with allocation\n");
        return 1;
    }    
    org = memset(test_alloc, c, n);
    ft = ft_memset(test2_alloc, c, n);
    if(strcmp(org, ft)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s %c %ld\n", test, c, n);
        fprintf(errorLog,"memset: %s\n", org);
        fprintf(errorLog,"ft_memset: %s\n", ft);
        fprintf(errorLog,"---------\n");
        fail_memset += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    free(test_alloc);
    free(test2_alloc);
    return(test_count + 1);
}

int memset_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_memset\n" RESET);
    test_count = memset_cmp(test_count, "fnjkdvbs", 'c', 2);
    test_count = memset_cmp(test_count, "    scnaocuw9/", 'a', 10);
    test_count = memset_cmp(test_count, "fnjkdvbs", '\n',  4);
    test_count = memset_cmp(test_count, "snsicnsk sjknsjanc", 0,  10);
    test_count = memset_cmp(test_count, "fnjkdvbs\n", 255,  0);
    test_count = memset_cmp(test_count, "fnjkdvbs\n", 's',  2);
    test_count = memset_cmp(test_count, "fnjkdvb0", 's',  6);
    test_count = memset_cmp(test_count, "NULL", 0,  0);
    return(fail_memset);
}






