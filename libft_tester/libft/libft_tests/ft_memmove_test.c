#include "../libft_tester.h"
#include <string.h>

int fail_memmove = 0;

int memmove_cmp(int test_count, char *test, char *test2, size_t n)
{
    FILE 	*errorLog;
    char *org;
    char *ft;
    char *test_alloc;
    char *test2_alloc;
    char *test_dub;
    char *test2_dub;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        printf("Error opening log file\n");
        return 1;
    }
    test_alloc = strdup(test);
    test2_alloc = strdup(test2); 
    test_dub = strdup(test);
    test2_dub = strdup(test2);
    if(test_alloc == NULL || test2_alloc == NULL || test2_dub == NULL || test2_dub == NULL)
    {   
        if(test_alloc)
            free(test_alloc);
        if(test2_alloc)
            free(test2_alloc);
        if(test_dub)
            free(test_dub);
        if(test2_dub)
            free(test2_dub);
        printf("Error with test2_dub\n");
        return 1;
    }    
    org = memmove(test_dub, test2_dub, n);
    ft = ft_memmove(test_alloc, test2_alloc, n);
    if(strcmp(org, ft)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s %s %ld\n", test, test2, n);
        fprintf(errorLog,"memmove: %s\n", org);
        fprintf(errorLog,"ft_memmove: %s\n", ft);
        fprintf(errorLog,"---------\n");
        fail_memmove += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    free(test_dub);
    free(test2_dub);
    free(test_alloc);
    free(test2_alloc);
    return(test_count + 1);
}

int memmove_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_memmove\n" RESET);
    test_count = memmove_cmp(test_count, "fnjkdvbs", "scnaocuw9", 2);
    test_count = memmove_cmp(test_count, "    scnaocuw9/", "    scnaocuw9/", 10);
    test_count = memmove_cmp(test_count, "fnjkdvbs", "snsicnsk",  4);
    test_count = memmove_cmp(test_count, "snsicnsk sjknsjanc", "snsicnsk fnjkdvbs",  10);
    test_count = memmove_cmp(test_count, "fnjkdvbs\n", "fnjkdvbs\n",  0);
    test_count = memmove_cmp(test_count, "fnjkdvbs\n", "fnjkdvbs\n",  2);
    test_count = memmove_cmp(test_count, "fnjkdvb0", "fnjkdvb0",  6);
    test_count = memmove_cmp(test_count, "NULL", "NULL",  0);
    return(fail_memmove);
}





