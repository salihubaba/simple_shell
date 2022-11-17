#include "main.h"

/**
 * main - a shell
 * @ac: argumrnt count
 * @av: argument vector
 *
 * Return: 0, always
 */
int main(int ac, char ** av)
{
	size_t n = 10;
	char *buf = NULL;

	printf("#cisfun$ ");
	getline(&buf, &n, stdin);

	printf("%s", buf);
	free(buf);
	return (0);
}
