#include <stdio.h>

int main()
{
	int n, i;
	printf("Enter the number of process: ");
	scanf("%d" , &n);

	int bt[n],bt1[n],endt[n],wt[n];
	printf("Enter the Burst time of process: ");
	for(i=0; i<n; i++)
	{
		scanf("%d", &bt[i]);
		bt1[i]=bt[i];
	}

	int gtime=0, tq, count=0;
	printf("Enter the time quantum: ");
	scanf("%d", &tq);
	int i=0;
	while(count!=n)
	{
		if(bt[i]!=0)
		{
			if(tq<bt[i])
			{
				bt[i]-=tq;
				gtime+=tq;
			}
			else
			{
				gtime+=bt[i];
				bt[i]=0;
				endt[i]=gtime;
				count++;
			}
		}
		i=(i+1)%n;
	}

	float avgwt=0, avgtat=0;
	for(i=0; i<n; i++)
	{
		avgtat+=endt[i];
		avgwt+=endt[i]-bt1[i];
	}
	avgwt/=(n*1.0);
	avgtat/=(n/1.0);

	printf("The average waiting time is %f\n", avgwt);
	printf("The average turnaround time is %f\n", avgtat);
	return 0;
}