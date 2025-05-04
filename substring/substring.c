#include <stdlib.h>
#include <string.h>
#include "substring.h"

/* Helper function to get index of a word in list, -1 if not found */
int get_word_index(const char *word, const char **words, int nb_words)
{
    int i;
    for (i = 0; i < nb_words; i++)
    {
        if (strcmp(word, words[i]) == 0)
            return i;
    }
    return -1;
}

int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
    int *result = NULL;
    int result_size = 0;
    int s_len = strlen(s);
    int word_len = strlen(words[0]);
    int total_len = word_len * nb_words;
    int i, j, k;

    if (!s || !words || nb_words == 0 || !n || s_len < total_len)
        return NULL;

    /* Build word count */
    int *word_freq = calloc(nb_words, sizeof(int));
    for (i = 0; i < nb_words; i++)
    {
        for (j = i + 1; j < nb_words; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
                break;
        }
        word_freq[i]++;
    }

    for (i = 0; i <= s_len - total_len; i++)
    {
        int *seen = calloc(nb_words, sizeof(int));
        for (j = 0; j < nb_words; j++)
        {
            int start = i + j * word_len;
            char *substr = strndup(s + start, word_len);
            int idx = get_word_index(substr, words, nb_words);
            free(substr);

            if (idx == -1)
            {
                free(seen);
                break;
            }
            seen[idx]++;
            if (seen[idx] > word_freq[idx])
            {
                free(seen);
                break;
            }
        }
        if (j == nb_words)
        {
            result = realloc(result, sizeof(int) * (result_size + 1));
            result[result_size++] = i;
        }
        if (seen)
            free(seen);
    }

    *n = result_size;
    if (result_size == 0)
    {
        free(result);
        return NULL;
    }

    return result;
}
