#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>

struct msgbuf{
	long type;
	char text[100];
}message;

int main(void)
{
	int key, msgid;
	key = ftok("5a.c",65);
	msgid = msgget(key,0666|IPC_CREAT);

	msgrcv(msgid,&message, sizeof(message), 1, 0);		// 1 signifies msg type
	printf("Message Recieved: %s\n", message.text);
	//msgctl(msgid,IPC_RMID,NULL);

	return 0;
}