#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int fd;
	fd = open("connection", O_RDWR);
	char buf[20];
	printf("Server Program:\n");
	read(fd, buf, 20);
	printf("The message is %s\n", buf);
	close(fd);
	return 0;
}