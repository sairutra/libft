#include "../libft_tester.h"
#include <string.h>
#include <fcntl.h>

int fail_putchar = 0;

int compareFile(FILE * fPtr1, char test, int * line, int * col)
{
    char ch1, ch2;
    *line = 1;
    *col  = 0;

    // Input character from both files
    ch1 = fgetc(fPtr1);
    ch2 = test;
    // If characters are not same then return -1
    if (ch1 != ch2)
        return -1;

    return 0;
}

int compare_files(int test_count, char test)
{
	int diff;
	int line, col;
	char s;
	FILE * fPtr1; 
	FILE 	*errorLog;
	fPtr1 = fopen("libft_tests/putchar_ft.txt", "r");
    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
	s = '0';

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr1 == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        return(-1);
    }
    /* Call function to compare file */
    diff = compareFile(fPtr1, test, &line, &col);

	rewind(fPtr1);
    if (diff != 0)
    {
        printf(RED "%d FAIL "RESET, test_count);
		fprintf(errorLog,"---------\n");
		fprintf(errorLog,"File not equal error\n");
		fprintf(errorLog,"test: %d\n", test_count);
		fprintf(errorLog,"testcase: %c\n", test);
        fprintf(errorLog,"Line: %d, col: %d\n", line, col);
		fprintf(errorLog,"function\n");
		while((s=fgetc(fPtr1))!=EOF) 
		{
      		fprintf(errorLog,"%c",s);
   		}
		fprintf(errorLog,"\n");
		fprintf(errorLog,"---------\n");
        fail_putchar += 1;
    }
    /* Finally close files to release resources */
    fclose(fPtr1);
	fclose(errorLog);
    return 0;
}



int putchar_cmp(int test_count, int test)
{
    int fd;
    fclose(fopen("libft_tests/putchar_ft.txt", "w"));
    fd = open("libft_tests/putchar_ft.txt", O_RDWR);
    ft_putchar_fd(test, fd);
    close(fd);
    compare_files(test_count, test);
    if(fail_putchar == 0)
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int putchar_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_putchar\n" RESET);
    test_count = putchar_cmp(test_count, 'a');
    test_count = putchar_cmp(test_count, 'b');
    test_count = putchar_cmp(test_count, '\200');
    test_count = putchar_cmp(test_count, '\n');
    test_count = putchar_cmp(test_count, '%');
    test_count = putchar_cmp(test_count, 0);
    test_count = putchar_cmp(test_count, ' ');
    test_count = putchar_cmp(test_count, '_');
    return(fail_putchar);
}






