#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - waits after a program executes
 * Return: int
*/

int main(void)
{
	pid_t child_pid = fork();
	pid_t parent_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i = 0;

	parent_pid = getpid();
	while (i < 5)
	{
		if (child_pid == 0)
		{
			printf("Before\n");
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:\n");
			}
			printf("after\n");
			exit(0);
		}
		else if (child_pid > 0)
		{
			printf("%u the parent pid\n", parent_pid);
			wait(NULL);
			child_pid = fork();
			printf("%u the child pid\n", child_pid);
		}
		else
		{
			printf("%u the parent pid\n", parent_pid);
			exit(1);
		}
		i++;
	}
	return (0);
}
