#include "libstring_functions.h"

/**
 * f_line_count - counts the number of lines in the file
 * and the line number where sub occurs, 0 if not found or empty.
 * @filename: name of file to count.
 * @sub: an optional string to be searched for in a file.
 * Description:
 * A string can be searched for in a file using sub.
 * Set sub to "" if no string should be searched for.
 *
 * Return: an array of:
 * the number of lines in the file
 * the line number where sub occurs
 */
int *f_line_count(char *filename, char *sub)
{
	char *buffer = 0, flag = 0;
	size_t n = 0, l1;
	ssize_t nread;
	FILE *stream;
	int *count, i, j;

	stream = fopen(filename, "r");
	if (!stream)
		return (NULL);

	count = malloc(sizeof(int) * 2);
	if (!count)
		return (NULL);

	i = j = 0;
	l1 = strlen(sub);

	while ((nread = getline(&buffer, &n, stream)) != -1)
	{
		if (!(strncmp(sub, buffer, l1)))
		{
			j++;
			flag = 1;
		}

		i++;

		if (flag == 0)
			j++;
	}

	if (!l1 || !flag)
		j = 0;
	count[0] = i;
	count[1] = j;

	free(buffer);
	fclose(stream);

	return (count);
}
