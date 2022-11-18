#include "main.h"

void execmd(char **av)
{

	//char *command = NULL;

	if (av)
	{
		
	if (execve(av[0], av, NULL) == -1)
		perror("Error:");
	
	}


}
