#include "norminette.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
 #include <ctype.h>

int status = 0;
char * normpath;


void	 check_norminette()
{
	pid_t pid;
	int sysret = -1;
	int wstatus = -1;
	int fd;
	char buf[10000];
	ssize_t read_ret;
	char *ret;

	ret = NULL;

	freopen(NORMLOCLOGS, "a+", stdout); 
	pid = fork();
	if(pid == 0)
	{		
		sysret = system("type norminette");
		freopen("/dev/tty", "w", stdout);
		if(sysret == -1)
		{
			printf("error in system function call in check_norminette  %s\n", NORMLOCLOGS);
			exit(EXIT_FAILURE);
		}
		if(sysret != 0) 
		{
			printf("Norminette not found  %s\n", NORMLOCLOGS);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &wstatus, 0);
		freopen("/dev/tty", "w", stdout);
		fd = open(NORMLOCLOGS, O_RDONLY);
		if(fd == -1)
		{
			printf("error in opening file descriptor of %s\n", NORMLOCLOGS);
			exit(EXIT_FAILURE);
		}
		read_ret = read(fd, buf, 10000);
		if(read_ret == -1)
		{
			printf("error in reading file descriptor of %s\n", NORMLOCLOGS);
			exit(EXIT_FAILURE);
		}
		close(fd);
		buf[read_ret - 1] = '\0';
		ret = strdup(strchr(buf, '/'));
		if(ret == NULL)
		{
			printf(RED "Error with allocated memory for norminette path in norminette checker \n" RESET);
		}
		normpath = ret;
		status += wstatus;
	}
	if(wstatus != 0 && pid != 0)
	{
		printf("wstatus: %d\n", wstatus);
		printf(RED "Something went wrong check %s\n" RESET, NORMLOCLOGS);
		if(sysret != -1 && sysret != 0)
			printf(RED "Norminette is not installed\n" RESET);
	}
}

void norminette_tester(char ** argv, char ** envp)
{
	pid_t pid;
	int wstatus = -1;
	int estatus = 0;

	printf(BMAG "%s\t" RESET, argv[1]);
	freopen(NORMLOGS, "a+", stdout); 
	pid = fork();

	
	if(pid == 0)
	{
		chdir(NORMFOLDER);
		estatus = execve(normpath, argv, envp);
		if(estatus == -1)
		{
			printf("Error with execve in norminette_tester function\n");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &wstatus, 0);
	}
	freopen("/dev/tty", "w", stdout);
	printf("\033[28G");
	if(wstatus != 0)
		printf(RED "FAIL\n" RESET);
	if(wstatus == 0)
		printf(GRN "OK\n" RESET);
	status += wstatus;
}

int main(int argc, char **argv, char **envp)
{
	freopen(NORMLOGS, "w", stdout);
	freopen(NORMLOCLOGS, "w", stdout);
	freopen("/dev/tty", "w", stdout);
	(void)argc;
	(void)argv;
	char ** normargv;
	int index;

	index = 1;

	check_norminette();

	normargv = malloc(sizeof(char**) * 2);
	
	if(normargv == NULL)
	{
		printf("Error in allocated memory for normargv in Norminette tester\n");
	}

	normargv[0] = "norminette";
	normargv[2] = NULL;



	printf(YEL "Norminette\n" RESET);

	while(argv[index] != NULL)
	{
		normargv[1] = argv[index];
		norminette_tester(normargv, envp);
		index++;
	}

	if(status != 0)
		printf(RED "There was an error, check %s\n" RESET, NORMLOGS);
	free(normargv);
	free(normpath);
	return(0);
}