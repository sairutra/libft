#include "../libft_tester.h"
#include <string.h>

int fail_calloc = 0;

int calloc_cmp(int test_count, size_t nmemb, size_t n)
{
    FILE 	*errorLog;
    char * calloc_vptr;
    char * ft_calloc_vptr;
    size_t error_index;

    error_index = 0;
    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        printf("Error opening log file\n");
        return 1;
    }

    calloc_vptr = calloc(nmemb, n);
    if(calloc_vptr == NULL)
    {
        printf("calloc error\n");
        return 1;
    }
    ft_calloc_vptr = ft_calloc(nmemb, n);
    if(ft_calloc_vptr == NULL)
    {
        if(calloc_vptr)
            free(calloc_vptr);
        printf("ft_calloc error\n");
        return 1;
    }

    while(error_index != (nmemb * n))
    {
        if((char)calloc_vptr[error_index] != (char)ft_calloc_vptr[error_index]) 
        {
            printf(RED "%d FAIL "RESET, test_count);
            fprintf(errorLog,"error\n");
            fprintf(errorLog,"test number: %d\n", test_count);
            fprintf(errorLog,"test case: nmemb %ld n %ld\n", nmemb, n);
            fprintf(errorLog,"calloc: %c\n", (char)calloc_vptr[error_index]);
            fprintf(errorLog,"ft_calloc: %c\n", (char)ft_calloc_vptr[error_index]);
            fprintf(errorLog,"---------\n");
            fail_calloc += 1;
        }
        error_index++;
    }
    printf(GRN "%d OK " RESET, test_count);
    free(calloc_vptr);
    free(ft_calloc_vptr);
    return(test_count + 1);
}

int calloc_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_calloc\n" RESET);
    test_count = calloc_cmp(test_count, 1, sizeof(char));
    test_count = calloc_cmp(test_count, 1000, sizeof(char));
    test_count = calloc_cmp(test_count, 1000000, sizeof(char));
    test_count = calloc_cmp(test_count, 1, sizeof(int));
    test_count = calloc_cmp(test_count, 1000, sizeof(int));
    test_count = calloc_cmp(test_count, 1000000, sizeof(int));
    test_count = calloc_cmp(test_count, 1, sizeof(float));
    test_count = calloc_cmp(test_count, 1000, sizeof(float));
    test_count = calloc_cmp(test_count, 1000000, sizeof(float));
    test_count = calloc_cmp(test_count, 1, sizeof(void));
    test_count = calloc_cmp(test_count, 1000, sizeof(void));
    test_count = calloc_cmp(test_count, 1000000, sizeof(void));
    test_count = calloc_cmp(test_count, 1, 0);
    test_count = calloc_cmp(test_count, 1000, 0);
    test_count = calloc_cmp(test_count, 1000000, 0);
    test_count = calloc_cmp(test_count, 0,1);
    test_count = calloc_cmp(test_count, 0,1000);
    test_count = calloc_cmp(test_count, 0,1000000);
    return(fail_calloc);
}


