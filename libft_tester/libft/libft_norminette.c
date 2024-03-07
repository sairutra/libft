#include "libft_tester.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int status = 0;

void norminette_tester(char ** argv, char ** envp)
{
	pid_t pid;
	int wstatus = 0;
	
	printf(BMAG "%s" RESET, argv[1]);
	freopen(NORMLOGS, "a+", stdout); 
	pid = fork();
	if(pid == 0)
	{
		chdir(NORMFOLDER);
		execve(NORMINETTE, argv, envp);
	}
	else
	{
		waitpid(pid, &wstatus, 0);
	}
	freopen("/dev/tty", "w", stdout);
	if(wstatus != 0)
		printf(RED "\tFAIL\n" RESET);
	if(wstatus == 0)
		printf(GRN "\tOK\n" RESET);
	status += wstatus;
}

int main(int argc, char **argv, char **envp)
{
	freopen(NORMLOGS, "w", stdout);
	freopen("/dev/tty", "w", stdout);
	(void)argc;
	(void)argv;
	char ** functionlist;
	char ** normargv;
	int index;

	index = 0;

	functionlist = malloc(sizeof(char**) * 34);

	if(functionlist == NULL)
	{
		printf("Error in allocated memory for functionlist in Norminette tester\n");
	}

	functionlist[0] = ATOI;
	functionlist[1] = BZERO;
	functionlist[2] = CALLOC;
	functionlist[3] = ISALNUM;
	functionlist[4] = ISALPHA;
	functionlist[5] = ISASCII;
	functionlist[6] = ISDIGIT;
	functionlist[7] = ISPRINT;
	functionlist[8] = ITOA;
	functionlist[9] = MEMCHR;
	functionlist[10] = MEMCMP;
	functionlist[11] = MEMCPY;
	functionlist[12] = MEMMOVE;
	functionlist[13] = MEMSET;
	functionlist[14] = PUTCHAR;
	functionlist[15] = PUTENDL;
	functionlist[16] = PUTNBR;
	functionlist[17] = PUTSTR;
	functionlist[18] = SPLIT;
	functionlist[19] = STRCHR;
	functionlist[20] = STRDUP;
	functionlist[21] = STRITERI;
	functionlist[22] = STRJOIN;
	functionlist[23] = STRLCAT;
	functionlist[24] = STRLCPY;
	functionlist[25] = STRLEN;
	functionlist[26] = STRMAPI;
	functionlist[27] = STRNCMP;
	functionlist[28] = STRNSTR;
	functionlist[29] = STRRCHR;
	functionlist[30] = STRTRIM;
	functionlist[31] = SUBSTR;
	functionlist[32] = TOLOWER;
	functionlist[33] = TOUPPER;
	functionlist[34] = NULL;

	normargv = malloc(sizeof(char**) * 2);
	
	if(normargv == NULL)
	{
		printf("Error in allocated memory for normargv in Norminette tester\n");
	}

	normargv[0] = "norminette";
	normargv[2] = NULL;


	printf(YEL "Norminette\n" RESET);

	while(functionlist[index] != NULL)
	{
		normargv[1] = functionlist[index];
		norminette_tester(normargv, envp);
		index++;
	}

	if(status != 0)
		printf(RED "There was an error, check %s\n" RESET, NORMLOGS);
	free(normargv);
	free(functionlist);
	return(0);
}