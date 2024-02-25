#include "../libft_tester.h"
#include <ctype.h>

int fail_ascii = 0;

int ascii_cmp(int test_count, int c)
{
    FILE *errorLog;
    int org_ascii;
    int ft_ascii;

    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {   
        printf("Error opening log file\n");
        return 1;
    }

    org_ascii = isascii(c);
    ft_ascii = ft_isascii(c);
    if(org_ascii == 0 && ft_ascii != 0) 
    {
        printf(RED "%d FAIL "RESET, test_count);
        fprintf(errorLog,"error\n");
        fprintf(errorLog,"test number: %d\n", test_count);
        fprintf(errorLog,"test case: %d\n", c);
        fprintf(errorLog,"org_ascii: %c\n", org_ascii);
        fprintf(errorLog,"ft_ascii: %c\n", ft_ascii);
        fprintf(errorLog,"---------\n");
        fail_ascii += 1;
    }
    else
        printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int ascii_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_isascii\n" RESET);
    test_count = ascii_cmp(test_count, 'a');
    test_count = ascii_cmp(test_count, 'A');
    test_count = ascii_cmp(test_count, 'z');
    test_count = ascii_cmp(test_count, '\n');
    test_count = ascii_cmp(test_count, '\200');
    test_count = ascii_cmp(test_count, '\100');
    test_count = ascii_cmp(test_count, 359);
    test_count = ascii_cmp(test_count, 255);
    test_count = ascii_cmp(test_count, '"');
    test_count = ascii_cmp(test_count, ' ');
    test_count = ascii_cmp(test_count, 1243);
    return(fail_ascii);
}





