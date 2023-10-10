#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - prints "$ "
 * Return: int
*/
int main() {
    char *command = NULL;
    size_t len = 0;
    while (1) {
        printf("$ ");
        getline(&command, &len, stdin);
        printf("%s", command);
    }
    free(command);
    return 0;
}
