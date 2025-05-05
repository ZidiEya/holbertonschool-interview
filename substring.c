#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * cmp_word_counts - Compare two word count hash tables.
 * @a: First hash table.
 * @b: Second hash table.
 * @nb_words: Number of words to compare.
 * @words: Array of words.
 * Return: 1 if equal, 0 otherwise.
 */
int cmp_word_counts(int *a, int *b, int nb_words, char const **words)
{
	int i;

	for (i = 0; i < nb_words; i++)
	{
		if (a[i] != b[i])
			return (0);
	}
	return (1);
}

/**
 * find_substring - Finds starting indices of substrings that are
 * a concatenation of all the words in a given list.
 * @s: Input string to search in.
 * @words: Array of words to match in substrings.
 * @nb_words: Number of words.
 * @n: Pointer to the number of matches found.
 * Return: Array of starting indices or NULL.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j, k, idx = 0, len_s, word_len, substr_len;
	int *results = NULL;
	int *target_counts, *current_counts;

	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	word_len = strlen(words[0]);
	len_s = strlen(s);
	substr_len = word_len * nb_words;
	*n = 0;

	target_counts = calloc(nb_words, sizeof(int));
	current_counts = calloc(nb_words, sizeof(int));
	results = malloc(sizeof(int) * (len_s - substr_len + 1));
	if (!target_counts || !current_counts || !results)
		return (NULL);

	for (i = 0; i < nb_words; i++)
	{
		for (j = 0; j < nb_words; j++)
		{
			if (strcmp(words[i], words[j]) == 0)
			{
				target_counts[j]++;
				break;
			}
		}
	}

	for (i = 0; i <= len_s - substr_len; i++)
	{
		memset(current_counts, 0, sizeof(int) * nb_words);
		for (j = 0; j < nb_words; j++)
		{
			const char *word = s + i + j * word_len;

			for (k = 0; k < nb_words; k++)
			{
				if (strncmp(word, words[k], word_len) == 0)
				{
					current_counts[k]++;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words && cmp_word_counts(target_counts, current_counts, nb_words, words))
			results[(*n)++] = i;
	}

	free(target_counts);
	free(current_counts);

	if (*n == 0)
	{
		free(results);
		return (NULL);
	}
	return (results);
}
