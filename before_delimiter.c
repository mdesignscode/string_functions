#include "libstring_functions.h"

/**
 * before_delim - counts the letters befor a delimiter.
 * @str: string to be counted.
 * @token: string of delimiters.
 *
 * Return: an array of the letters before each delimiter.
 */
int *before_delim(char *str, char *token)
{
	int words, *before_delim, letters, i, j, k;
	char flag;

	words = wrdcnt(str, token);

	before_delim = malloc(sizeof(int) * words);
	if (!before_delim)
		return (NULL);

	i = 0;
	for (k = 0; k < words; k++)
	{
		flag = 0;
		letters = 0;
		for (; str[i]; i++)
		{
			for (j = 0; token[j]; j++)
			{
				if (str[i] == token[j])
				{
					flag = 1;
					i++;
				}
			}
			if (flag)
				break;
			if (!flag)
				letters++;
		}
		before_delim[k] = letters;
	}

	return (before_delim);
}
