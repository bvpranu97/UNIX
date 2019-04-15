#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	mkfifo("fifo1",0777);		//0777 means everyone can r,w,ex the file
	int fd;
	fd = open("fifo1", O_RDWR);
	char buf[20]=" ";
	printf("Client Program:\nEnter the message:");
	scanf("%s", buf);
	write(fd, buf, 20);
	close(fd);
	return 0;
}