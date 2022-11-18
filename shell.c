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
	char *buf_copy = NULL;
	int num_tokens = 0;
	char *token;
	int i;
	char *delim = " \n";
	pid_t pid;

	while (1)
	{
	printf("#cisfun$ ");
	get = getline(&buf, &n, stdin);
	if (get == -1)
	{
		printf("Exiting shell\n");
		return (-1);
	}
		
	buf_copy = malloc(sizeof(char) * get);
	if (buf_copy == NULL)
	{
		perror("memory allocation error");
		return (-1);
	}

	strcpy(buf_copy, buf);

	token = strtok(buf, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	av = malloc(sizeof(char) * num_tokens);

	token = strtok(buf_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		av[i] = malloc(sizeof(char) * strlen(token));
		strcpy(av[i], token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;

	pid = fork();
	if (pid == 0)
		execmd(av);
	else
		wait(NULL);
	}
	free(buf);
	/* free(av); */
	free(buf_copy);

	return (0);
}


