#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *test;
	test = malloc(10);
	free(test);
	return 0;
}