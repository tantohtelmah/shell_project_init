#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
    printf("%p env\n", (void *)env);
	printf("%p environ\n", (void *)environ);
    return 0;
}
