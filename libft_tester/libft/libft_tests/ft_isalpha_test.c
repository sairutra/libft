#include "../libft_tester.h"
#include <ctype.h>

int fail_alpha = 0;

int alpha_cmp(int test_count, int c)
{
    FILE *errorLog;
    int org_alpha;
    int ft_alpha;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        printf("Error opening log file\n");
        return 1;
    }

    org_alpha = isalpha(c);
    ft_alpha = ft_isalpha(c);
    if(org_alpha == 0 && ft_alpha != 0) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %d\n", c);
        fprintf(errorLog,"org_alpha: %c\n", org_alpha);
        fprintf(errorLog,"ft_alpha: %c\n", ft_alpha);
        fprintf(errorLog,"---------\n");
        fail_alpha += 1;
    }
    else
        printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int alpha_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_isalpha\n" RESET);
    test_count = alpha_cmp(test_count, 'a');
    test_count = alpha_cmp(test_count, 'A');
    test_count = alpha_cmp(test_count, 'z');
    test_count = alpha_cmp(test_count, '\n');
    test_count = alpha_cmp(test_count, '\200');
    test_count = alpha_cmp(test_count, '\100');
    test_count = alpha_cmp(test_count, '8');
    test_count = alpha_cmp(test_count, '/');
    test_count = alpha_cmp(test_count, '"');
    test_count = alpha_cmp(test_count, ' ');
    return(fail_alpha);
}




