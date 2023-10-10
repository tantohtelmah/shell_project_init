#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name) {
    extern char **environ;
    size_t len = strlen(name);
    for (char **env = environ; *env != NULL; env++) {
        if (strncmp(*env, name, len) == 0 && (*env)[len] == '=') {
            return &((*env)[len + 1]);
        }
    }
    return NULL;
}

int main() {
    char *path = _getenv("PATH");
    if (path != NULL) {
        printf("PATH: %s\n", path);
    } else {
        printf("PATH not found\n");
    }
    return 0;
}
