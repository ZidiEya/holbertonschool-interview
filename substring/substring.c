#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n) {
    int word_len = strlen(words[0]);
    int total_len = word_len * nb_words;
    int *indices = malloc(sizeof(int) * (strlen(s) / word_len));
    *n = 0;

    for (int i = 0; i <= strlen(s) - total_len; i++) {
        int found = 1;
        int *word_count = calloc(nb_words, sizeof(int));

        for (int j = 0; j < nb_words; j++) {
            int word_found = 0;
            for (int k = 0; k < nb_words; k++) {
                if (word_count[k] == 0 && strncmp(s + i + j * word_len, words[k], word_len) == 0) {
                    word_count[k] = 1;
                    word_found = 1;
                    break;
                }
            }
            if (!word_found) {
                found = 0;
                break;
            }
        }

        if (found) {
            indices[*n] = i;
            (*n)++;
        }

        free(word_count);
    }

    return indices;
}
