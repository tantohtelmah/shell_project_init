#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(char *str, const char *delim, int *num_words) {
    char **words = NULL;
    char *token;
    int count = 0;

    token = strtok(str, delim);
    while (token != NULL) {
        words = realloc(words, (count + 1) * sizeof(char *));
        words[count] = strdup(token);
        count++;
        token = strtok(NULL, delim);
    }

    *num_words = count;
    return words;
}

int main() {
    char str[] = "This is a test string";
    const char delim[] = " ";
    int num_words;
    char **words = split_string(str, delim, &num_words);

    printf("Number of words: %d\n", num_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);

    return 0;
}
