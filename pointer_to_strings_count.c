#include "libstring_functions.h"

/**
 * strings_count - counts the number of words,
 * letters and total letters at a pointer to strings.
 * @strings: an array of strings.
 * Description: COUNT[0]: number of pointers the pointer points to
 * COUNT[1]: the number of letters in each pointer
 * CONT[2]: total number of letters.
 *
 * Return: an array with:
 * a pointer to the number of words the pointer points to
 * an array of the number of letters in each word
 * a pointer to the total number of words the pointer points to
 */
size_t **strings_count(char **strings)
{
	size_t words, i, **array, letters, total;

	words = letters = total = 0;
	/* counting words in array */
	for (i = 0; strings[i]; i++)
		words++;

	/* storing word count in array */
	array = malloc(sizeof(size_t *) * 3);
	if (!array)
		return (NULL);

	array[0] = malloc(sizeof(size_t));
	if (!array[0])
		return (NULL);
	array[0] = &words;

	/* counting the number of letters in each word */
	array[1] = malloc(sizeof(size_t) * words);
	if (!array[1])
		return (NULL);

	for (i = 0; i < words; i++)
	{
		letters = strlen(strings[i]);
		array[1][i] = letters;
		total += letters;
	}

	array[2] = &total;

	return (array);
}
