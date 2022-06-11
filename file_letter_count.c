#include "libstring_functions.h"

/**
 * f_letter_count - counts the letters on each line in a file
 * @filename: name of file to count.
 *
 * Return: an array of the number of letters on each line.
 */
int *f_letter_count(char *filename)
{
	char *buffer;
	size_t n;
	ssize_t nread;
	FILE *stream;
	int i, k;
	int *letters, *lines;

	lines = f_line_count(filename, "");

	/* opening file */
	stream = fopen(filename, "r");
	if (!stream)
		return (NULL);

	letters = malloc(sizeof(int) * *lines);
	if (!letters)
		return (NULL);

	buffer = 0;
	n = 0;
	i = 0;
	while ((nread = getline(&buffer, &n, stream)) != -1)
	{
		for (k = 0; buffer[k]; k++)
			;
		letters[i] = k;
		i++;
	}

	free(buffer);
	fclose(stream);
	free(lines);

	return (letters);
}
