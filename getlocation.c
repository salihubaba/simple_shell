#include "main.h"

char *get_location(char *input)
{
	char *path, *path_copy, *file_path;
	int input_length;
	char *path_token;
	int dir_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		input_length = strlen(input);
		path_token = strtok(path_copy, ":");
	while (path_token)
	{
		dir_len = strlen(path_token);
		file_path = malloc(input_length + dir_len + 2);
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, input);
		strcat(file_path, "\0");
	if (stat(file_path, &buffer) == 0)
	{
		free(path_copy);
		return (file_path);
	}
	else
	{
		free(file_path);
		path_token = strtok(NULL, ":");
	}
	}
	free(path_copy);
	}
	return (NULL);
}
