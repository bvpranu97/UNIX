#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>
int main(void)
{	
	int fd[2];		//fd[0] read end, fd[1] write end of a pipe
	int wstatus;
	char buf[100];

	pipe(fd);
	int nfds = 2;
	fd_set readfs;
	
	struct timeval t;

	t.tv_sec = 7;
	t.tv_usec = 0;
	
	FD_ZERO(&readfs);
	FD_SET(fd[0], &readfs);

	int ret = fork();
	if(ret == -1)
		printf("sdsds");
	
	if(ret == 0)
	{
		write(fd[1],"anmol",5);
	}
	else
	{
		int v = select(nfds,&readfs,NULL,NULL,&t);

		if(v == -1)
			printf("error");
		else if(v)
		{	
			read(fd[0],buf,10);
			printf("%s",buf);
			printf("Success");
			exit(0);
		}
		else
			printf("Time-Out");
	}
	return 0;
}