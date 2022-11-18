#include "main.h"

/**
 * main - a shell
 * @ac: argumrnt count
 * @av: argument vector
 *
 * Return: 0, always
 */
int main(int ac __attribute__((unused)), char **av)
{
	size_t n = 0;
	char *buf = NULL;
	ssize_t get;
	char *delim = " \n";
	char *buf_copy = NULL;
	int num_tokens = 0;
	char *token;
	int i;

	while (1)
	{
	printf("#cisfun$ ");
	get = getline(&buf, &n, stdin);
	if (get == -1)
	{
		printf("Exiting shell\n");
		return (-1);
	}
		

	// implementing the strtok
	buf_copy = malloc(sizeof(char) * get);
	if (buf_copy == NULL)
	{
		perror("memory allocation error");
		return (-1);
	}

	strcpy(buf_copy, buf);
	// CALCULATE THE TOTAL NO OF TOKENS
	token = strtok(buf, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	//allocate memory for argv to hold the separated strings
	av = malloc(sizeof(char) * num_tokens);
	//passing the separated strings into the array
	token = strtok(buf_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		av[i] = malloc(sizeof(char) * strlen(token));
		strcpy(av[i], token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	
	execmd(av);
	}

	//printf("%s\n", av);
	free(buf);
	//free(av);
	free(buf_copy);

	return (0);
}


