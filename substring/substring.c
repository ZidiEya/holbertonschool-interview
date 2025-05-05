#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_match - checks if a substring matches all words in any order
 * @s: the starting point in the string
 * @words: array of words to match
 * @nb_words: number of words
 * @word_len: length of each word
 * Return: 1 if all words match, 0 otherwise
 */
int is_match(const char *s, const char **words, int nb_words, int word_len)
{
    int *seen = calloc(nb_words, sizeof(int));
    if (!seen)
        return 0;

    for (int i = 0; i < nb_words; i++)
    {
        int found = 0;
        for (int j = 0; j < nb_words; j++)
        {
            if (!seen[j] && strncmp(s + i * word_len, words[j], word_len) == 0)
            {
                seen[j] = 1;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            free(seen);
            return 0;
        }
    }

    free(seen);
    return 1;
}

/**
 * find_substring - finds all substrings made of concatenated words
 * @s: input string
 * @words: list of words
 * @nb_words: number of words
 * @n: pointer to result count
 * Return: array of starting indices
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
    int word_len, total_len, str_len, *indices = NULL, count = 0;

    if (!s || !words || nb_words == 0 || !n)
        return NULL;

    word_len = strlen(words[0]);
    total_len = word_len * nb_words;
    str_len = strlen(s);

    indices = malloc(sizeof(int) * (str_len));
    if (!indices)
        return NULL;

    for (int i = 0; i <= str_len - total_len; i++)
    {
        if (is_match(s + i, words, nb_words, word_len))
            indices[count++] = i;
    }

    if (count == 0)
    {
        free(indices);
        indices = NULL;
    }

    *n = count;
    return indices;
}
