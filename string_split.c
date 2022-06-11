#include "libstring_functions.h"

/**
 * strsplt - splits a string by delimiter into
 * an array of each word of the string.
 * @str: string to split.
 * @token: string of delimiters.
 * @new_delim: string to split new array by.
 *
 * Return: a new array of strings.
 */
char **strsplt(char *str, char *token, char new_delim)
{
	char **split;
	int *array;
	int index, watch, assign, letters;
	int wc;


	wc = wrdcnt(str, token);

	split = malloc(sizeof(char *) * (wc + 1));
	if (!split)
		return (NULL);

	array = before_delim(str, token);
	assign = 0;
	for (index = 0; index < wc; index++)
	{
		letters = array[index];
		split[index] = malloc(sizeof(char) * letters + 2);
		if (!split[index])
			return (NULL);

		for (watch = 0; watch < letters; watch++)
		{
			split[index][watch] = str[assign++];
		}
		assign++;
		split[index][watch] = new_delim;
		split[index][watch + 1] = 0;
	}
	split[index] = NULL;

	free(array);

	return (split);
}
