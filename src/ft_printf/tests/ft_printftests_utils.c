#include "ft_printftests.h"

int compareFile(FILE * fPtr1, FILE * fPtr2, int * line, int * col)
{
    char ch1, ch2;

    *line = 1;
    *col  = 0;

    do
    {
        // Input character from both files
        ch1 = fgetc(fPtr1);
        ch2 = fgetc(fPtr2);
        
        // Increment line 
        if (ch1 == '\n')
        {
            *line += 1;
            *col = 0;
        }

        // If characters are not same then return -1
        if (ch1 != ch2)
            return -1;

        *col  += 1;

    } while (ch1 != EOF && ch2 != EOF);
    /* If both files have reached end */
    if (ch1 == EOF && ch2 == EOF)
        return 0;
    else
        return -1;
}

int compare_length(int test_count, int ft_outcome, int outcome)
{
    FILE 	*errorLog;
    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
	if(ft_outcome != outcome)
	{
        printf(RED "Length is not equal. Check error_log.txt\n" RESET);
        fprintf(errorLog,"Length error\n");
        fprintf(errorLog,"test: %d\n", test_count);
        fprintf(errorLog,"ft_print len: %d\n", ft_outcome);
        fprintf(errorLog,"print len: %d\n", outcome);
        fprintf(errorLog,"---------\n");
	}
    fclose(errorLog);
	return(ft_outcome - outcome);
}

int compare_files(int test_count)
{
	int diff;
	int line, col;
	char s;
	FILE * fPtr1; 
    FILE * fPtr2;
	FILE 	*errorLog;
	fPtr1 = fopen("ft_temp.txt", "r");
    fPtr2 = fopen("temp.txt", "r");
    errorLog = fopen("logs/error_log.txt", "a");
    if (errorLog == NULL)
    {
        printf("Error opening log file\n");
        return 1;
    }
	s = '0';

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr1 == NULL || fPtr2 == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        return(-1);
    }
    /* Call function to compare file */
    diff = compareFile(fPtr1, fPtr2, &line, &col);

	rewind(fPtr1);
	rewind(fPtr2);
    if (diff != 0)
    {
        printf(RED "Files are not equal. Check error_log.txt\n" RESET);
		fprintf(errorLog,"---------\n");
		fprintf(errorLog,"File not equal error\n");
		fprintf(errorLog,"test: %d\n", test_count);
        fprintf(errorLog,"Line: %d, col: %d\n", line, col);
		fprintf(errorLog,"ft_printf\n");
		while((s=fgetc(fPtr1))!=EOF) 
		{
      		fprintf(errorLog,"%c",s);
   		}
		printf("\nprintf\n");
		while((s=fgetc(fPtr2))!=EOF) 
		{
      		fprintf(errorLog,"%c",s);
   		}
		fprintf(errorLog,"\n");
		fprintf(errorLog,"---------\n");
    }
    /* Finally close files to release resources */
    fclose(fPtr1);
    fclose(fPtr2);
	fclose(errorLog);
    return 0;
}
