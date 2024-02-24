#include "../libft_tester.h"
#include <ctype.h>

int fail_alnum = 0;

int alnum_cmp(int test_count, int c)
{
    FILE *errorLog;
    int org_alnum;
    int ft_alnum;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        printf("Error opening log file\n");
        return 1;
    }

    org_alnum = isalnum(c);
    ft_alnum = ft_isalnum(c);
    if(org_alnum == 0 && ft_alnum != 0) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %d\n", c);
        fprintf(errorLog,"org_alnum: %c\n", org_alnum);
        fprintf(errorLog,"ft_alnum: %c\n", ft_alnum);
        fprintf(errorLog,"---------\n");
        fail_alnum += 1;
    }
    else
        printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int alnum_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_isalnum\n" RESET);
    test_count = alnum_cmp(test_count, 'a');
    test_count = alnum_cmp(test_count, 'A');
    test_count = alnum_cmp(test_count, '\n');
    test_count = alnum_cmp(test_count, '\200');
    test_count = alnum_cmp(test_count, '\100');
    test_count = alnum_cmp(test_count, '8');
    test_count = alnum_cmp(test_count, '/');
    test_count = alnum_cmp(test_count, '"');
    test_count = alnum_cmp(test_count, ' ');
    return(fail_alnum);
}



