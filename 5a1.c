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
	message.type = 1;		//1 signifies placing data on msg q

	printf("Enter message:\n");
	scanf("%[^\n]", message.text);
	msgsnd(msgid, &message, sizeof(message),0);
	printf("Message Sent: %s", message.text);

	return 0;
}