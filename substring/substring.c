#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - Finds all substrings containing all words from an array
 * @s: input string
 * @words: array of words
 * @nb_words: number of words
 * @n: pointer to store the number of indices found
 * Return: array of starting indices, or NULL
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
    int i, j, k, word_len, substr_len, str_len, index_count = 0;
    int *indices = NULL;
    char *curr;
    int *word_count, *seen;

    if (!s || !words || nb_words == 0 || !n)
        return (NULL);

    word_len = strlen(words[0]);
    substr_len = word_len * nb_words;
    str_len = strlen(s);

    if (str_len < substr_len)
        return (NULL);

    // Allocate memory for result
    indices = malloc(sizeof(int) * (str_len - substr_len + 1));
    if (!indices)
        return (NULL);

    // Count frequency of each word in input
    word_count = calloc(nb_words, sizeof(int));
    for (i = 0; i < nb_words; i++)
        for (j = 0; j < nb_words; j++)
            if (strcmp(words[i], words[j]) == 0)
                word_count[i]++;

    // Scan the string
    for (i = 0; i <= str_len - substr_len; i++)
    {
        seen = calloc(nb_words, sizeof(int));
        for (j = 0; j < nb_words; j++)
        {
            curr = strndup(s + i + j * word_len, word_len);
            for (k = 0; k < nb_words; k++)
            {
                if (strcmp(curr, words[k]) == 0)
                {
                    seen[k]++;
                    break;
                }
            }
            free(curr);
            if (k == nb_words || seen[k] > word_count[k])
            {
                break;
            }
        }
        if (j == nb_words)
            indices[index_count++] = i;
        free(seen);
    }

    *n = index_count;
    if (index_count == 0)
    {
        free(indices);
        return NULL;
    }

    return indices;
}
