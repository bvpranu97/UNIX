#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{	
	char cmd[20];
	int status;
	int a = fork();

	if(a == 0)
	{
		printf("This is child process\n");
		printf("Child process id: %d\n", getpid());
		printf("Parent process id: %d\n", getppid());
		printf("Enter the command: ");
		scanf("%s", cmd);
		system(cmd);
	}
	else
	{
		wait(&status);
		printf("This is parent process\n");
		printf("Grandparent process id: %d\n", getppid());
		printf("Parent process id: %d\n", getpid());
		printf("Child status: %d\n", status);
	}

	return 0;
}
