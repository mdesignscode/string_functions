/**
 * wrdcnt - counts the words in a string separated by a delimiter
 * @str: string to be counted.
 * @token: string of delimiters.
 *
 * Return: the number of words in the string.
 */
int wrdcnt(char *str, char *token)
{
	int words, i, j;
	char flag = 0;

	words = 0;
	for (i = 0; str[i]; i++)
	{
		for (j = 0; token[j]; j++)
		{
			if (str[i] == token[j] && str[i + 1] == token[j])
				flag = 1;
			if (str[i] == token[j] && str[i + 1] != token[j])
				flag = 0;
			if (!flag)
			{
				if (str[i] == token[j] && str[i + 1])
					words++;
			}
		}
	}
	words++;

	return (words);
}
