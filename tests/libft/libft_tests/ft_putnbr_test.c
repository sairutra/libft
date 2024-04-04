#include "../libft_tester.h"
#include <string.h>
#include <fcntl.h>

int fail_putnbr = 0;

int compareFile_putnbr(FILE * fPtr1, char *test, int * line, int * col)
{
    char ch1, ch2;
	int index;

	index = 0;
	*line = 1;
    *col  = 0;
	ch1 = '\0';
    // Input character from both files
    while(ch1 != EOF)
	{
		ch1 = fgetc(fPtr1);
		ch2 = test[index];
        if (ch1 == EOF)
            return (0);
		if (ch1 != ch2)
			return -1;
	    // If characters are not same then return -1
		index++;
	}
    return 0;
}

int compare_files_putnbr(int test_count, int test)
{
	int diff;
	int line, col;
	char s;
	FILE * fPtr1; 
	FILE 	*errorLog;



	fPtr1 = fopen("libft_tests/putnbr_ft.txt", "r");
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
	diff = compareFile_putnbr(fPtr1, ft_itoa(test), &line, &col);
	
	rewind(fPtr1);
    if (diff != 0)
    {
        printf(RED "%d FAIL "RESET, test_count);
		fprintf(errorLog,"---------\n");
		fprintf(errorLog,"File not equal error\n");
		fprintf(errorLog,"test: %d\n", test_count);
		fprintf(errorLog,"testcase: %d\n", test);
        fprintf(errorLog,"Line: %d, col: %d\n", line, col);
		fprintf(errorLog,"function\n");
		while((s=fgetc(fPtr1))!=EOF) 
		{
      		fprintf(errorLog,"%c",s);
   		}
		fprintf(errorLog,"\n");
		fprintf(errorLog,"---------\n");
        fail_putnbr += 1;
    }
    /* Finally close files to release resources */
    fclose(fPtr1);
	fclose(errorLog);
    return 0;
}



int putnbr_cmp(int test_count, int test)
{
    int fd;
    fclose(fopen("libft_tests/putnbr_ft.txt", "w"));
    fd = open("libft_tests/putnbr_ft.txt", O_RDWR);
    ft_putnbr_fd(test, fd);
    close(fd);
    compare_files_putnbr(test_count, test);
    if(fail_putnbr == 0)
		printf(GRN "%d OK " RESET, test_count);
    return(test_count + 1);
}

int putnbr_test()
{
    int  test_count = 1;
    printf("\n");
	printf(BMAG "ft_putnbr\n" RESET);
    test_count = putnbr_cmp(test_count, 0);
    test_count = putnbr_cmp(test_count, 1);
    test_count = putnbr_cmp(test_count, INT_MAX);
    test_count = putnbr_cmp(test_count, INT_MIN);
    test_count = putnbr_cmp(test_count, 1351546813);
    test_count = putnbr_cmp(test_count, -52454363);
    test_count = putnbr_cmp(test_count, 100);
	test_count = putnbr_cmp(test_count, 999);
    return(fail_putnbr);
}









