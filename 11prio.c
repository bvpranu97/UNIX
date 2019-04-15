#include <stdio.h>

int main()
{
	int n, i;
	printf("Enter the number of process: ");
	scanf("%d" , &n);

	int bt[n], p;
	printf("Enter the Priority Burst time of all process: \n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &p)
		scanf("%d", &bt[p-1]);
	}	

	int wt[n], tat[n];
	wt[0]=0;
	tat[0]=bt[0];
	float avgwt=wt[0], avgtat=tat[0];
	for(i=1; i<n; i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
		avgwt+=wt[i];
		tat[i]=wt[i]+bt[i];
		avgtat+=tat[i];
	}
	avgwt/=(n*1.0);
	avgtat/=(n/1.0);

	printf("The average waiting time is %f\n", avgwt);
	printf("The average turnaround time is %f\n", avgtat);
	return 0;
}