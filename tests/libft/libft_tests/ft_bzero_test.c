#include "../libft_tester.h"
#include <string.h>

int fail_bzero = 0;

int bzero_cmp(int test_count, char *test, size_t n)
{
    FILE 	*errorLog;
    char *test_alloc;
    char *test_dup;
    int error_index;

    error_index = 0;
    if(test)
    {
        test_alloc = malloc(strlen(test));
        if(test_alloc == NULL)
        {
            printf("Error with creating alloc string for testing\n");
            return 1;
        }
    }
    test_dup = strdup(test);
    if(test)
    {
        if(test_dup == NULL)
        {
            if(test_alloc)
                free(test_alloc);
            printf("Error with creating dup string for testing\n");
            return 1;
        }    
    }
    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        if(test_alloc)
            free(test_alloc);
        if(test_dup)
            free(test_dup);
        printf("Error opening log file\n");
        return 1;
    }

    bzero(test_alloc, n);
    ft_bzero(test_dup, n);
    if(strcmp(test_alloc, test_dup)) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %s\n", test);
        fprintf(errorLog,"bzero: %s\n", test);
        fprintf(errorLog,"ft_bzero: %s\n", test_dup);
        fprintf(errorLog,"strcmp %d\n", strcmp(test_alloc, test_dup));
        while(test_alloc[error_index] != '\0')
        {
            fprintf(errorLog,"bzero string: %c index: %d\n", test_alloc[error_index], error_index);
            error_index++;
        }
        error_index = 0;
        while(test_dup[error_index] != '\0')
        {
            fprintf(errorLog,"ft_bzero string: %c index: %d\n", test_dup[error_index], error_index);
            error_index++;
        }
        fprintf(errorLog,"---------\n");
        fail_bzero += 1;
    }
    else
		printf(GRN "%d OK " RESET, test_count);
    free(test_alloc);
    free(test_dup);
    return(test_count + 1);
}

int bzero_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_bzero\n" RESET);
    test_count = bzero_cmp(test_count, "1", 1);
    test_count = bzero_cmp(test_count, "12", 1);
    test_count = bzero_cmp(test_count, "123", 2);
    test_count = bzero_cmp(test_count, "1234", 2);
    test_count = bzero_cmp(test_count, "  12345", 5);
    test_count = bzero_cmp(test_count, "123 456", 5);
    test_count = bzero_cmp(test_count, "A2143244535", 7);
    test_count = bzero_cmp(test_count, "2143244535",  7);
    test_count = bzero_cmp(test_count, " ", 1);
    test_count = bzero_cmp(test_count, "asbj", 4);
    test_count = bzero_cmp(test_count, "       ", 1);
    return(fail_bzero);
}

