#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(void)
{
	struct sched_param sp;

	switch(sched_getscheduler(getpid()))
	{
		case SCHED_OTHER:printf("Other Scheduling algorithm\n");
				 break;
		case SCHED_FIFO: printf("FIFO Scheduling algorithm\n");
				 break;
		case SCHED_RR:	 printf("Round Robin Scheduling algorithm\n");
				 break;
	}
	
	printf("Max Scheduling priority for Round Robin %d\n", sched_get_priority_max(SCHED_RR));
	sp.sched_priority = 99;
	sched_setscheduler(getpid(), SCHED_RR, &sp);

	switch(sched_getscheduler(0))
	{
		case SCHED_OTHER:printf("Other Scheduling algorithm\n");
				 break;
		case SCHED_FIFO: printf("FIFO Scheduling algorithm\n");
				 break;
		case SCHED_RR:	 printf("Round Robin Scheduling algorithm\n");
				 break;
	}
	return 0 ;
}