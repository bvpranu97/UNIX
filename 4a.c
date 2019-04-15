#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void)
{
	int which = PRIO_PROCESS;
	int k, priority;
	id_t pid = getpid();
	int ret = getpriority(which, pid);

	printf("The priority is %d\n", ret);
	printf("Enter the new priority:");
	scanf("%d", &priority);
	k=setpriority(which, 0, priority);

	if(k==0)
	{
		ret=getpriority(which, pid);
		printf("The new priority is %d\n", ret);
	}
	else if(k==-1)
		printf("Cannot set priority\n");

	return 0;
}
