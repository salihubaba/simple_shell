#include "main.h"

char *get_location(char *input)
{
	char *path, *path_copy;
	size_t input_length;
	char *path_token;
	int dir_len;
	char *file_path;

	path = getenv("PATH");
	path_copy = strdup(path);
	input_length = strlen(input);
	path_token = strtok(path_copy, ":");
	dir_len = strlen(path_token);
	file_path = malloc(input_length + dir_len + 2);
	strcpy(file_path, path_token);
	strcat(file_path, "/");
	strcat(file_path, input);
	strcat(file_path, "\0");
}
