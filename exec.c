#include "main.h"

void execmd(char **av)
{

	char *input = NULL, *new_input = NULL;

	if (av)
	{
		input = av[0];
		new_input = get_location(input);
		
	if (execve(new_input, av, NULL) == -1)
		perror("Error:");
	
	}


}
