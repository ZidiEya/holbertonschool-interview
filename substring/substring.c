#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * struct word_node - a word entry for counting
 * @word: the word itself
 * @count: how many times it appears
 */
typedef struct word_node
{
    const char *word;
    int count;
} word_node;

/**
 * match_words - compare expected and actual word counts
 * Return: 1 if equal, 0 otherwise
 */
int match_words(word_node *expected, word_node *actual, int nb_words)
{
    for (int i = 0; i < nb_words; i++)
    {
        if (actual[i].count != expected[i].count)
            return 0;
    }
    return 1;
}

/**
 * find_substring - finds all starting indices of substrings in `s` that
 * are a concatenation of each word in `words` exactly once.
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
    int *indices = NULL;
    int str_len = strlen(s);
    int word_len, total_len;
    int i, j;

    *n = 0;

    if (!s || !words || nb_words == 0)
        return NULL;

    word_len = strlen(words[0]);
    total_len = word_len * nb_words;

    if (str_len < total_len)
        return NULL;

    // Create the expected word count
    word_node *expected = malloc(sizeof(word_node) * nb_words);
    for (i = 0; i < nb_words; i++)
    {
        expected[i].word = words[i];
        expected[i].count = 0;
        for (j = 0; j < i; j++)
        {
            if (strcmp(words[i], expected[j].word) == 0)
            {
                expected[j].count++;
                break;
            }
        }
        if (j == i)
            expected[i].count = 1;
    }

    // Main loop to check each possible starting point
    for (i = 0; i <= str_len - total_len; i++)
    {
        word_node *actual = malloc(sizeof(word_node) * nb_words);
        for (j = 0; j < nb_words; j++)
        {
            actual[j].word = words[j];
            actual[j].count = 0;
        }

        int matched = 1;
        for (j = 0; j < nb_words; j++)
        {
            const char *sub = s + i + j * word_len;
            int found = 0;

            for (int k = 0; k < nb_words; k++)
            {
                if (strncmp(sub, words[k], word_len) == 0)
                {
                    actual[k].count++;
                    if (actual[k].count > expected[k].count)
                        matched = 0;
                    found = 1;
                    break;
                }
            }

            if (!found || !matched)
                break;
        }

        if (matched && match_words(expected, actual, nb_words))
        {
            indices = realloc(indices, sizeof(int) * (*n + 1));
            indices[*n] = i;
            (*n)++;
        }

        free(actual);
    }

    free(expected);
    return indices;
}
